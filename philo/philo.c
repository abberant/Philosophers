/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:15:06 by aanouari          #+#    #+#             */
/*   Updated: 2023/05/31 05:19:51 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	_layout(t_table *round, char *exhibit)
{
	pthread_mutex_lock(round->philos->layout);
	printf("%ld ms %d %s", time_now() - round->philos->t_creation, round->order, exhibit);
	pthread_mutex_unlock(round->philos->layout);
}

void	partake(t_table *round)
{
	pthread_mutex_lock(&round->forks[round->order - 1]);
	_layout(round, TAKE_FORK);
	pthread_mutex_lock(&round->forks[round->order % round->n_philos]);
	_layout(round, TAKE_FORK);
	_layout(round, EAT);
	if (round->philos->circles > 0)
	{
		pthread_mutex_lock(&round->circle_n[round->order - 1]);
		round->philos->circles--;
		pthread_mutex_unlock(&round->circle_n[round->order - 1]);
	}
	pthread_mutex_lock(round->last_meal);
	round->last_meal_n = time_now();
	pthread_mutex_unlock(round->last_meal);
	usleep(round->philos->meal_span * 1000);
	pthread_mutex_unlock(&round->forks[round->order - 1]);
	pthread_mutex_unlock(&round->forks[round->order % round->n_philos]);
}

void	*routine(void *arg)
{
	t_table	*round;

	round = (t_table *)arg;
	round->last_meal_n = time_now();
	if (round->order % 2 == 0)
	{
		usleep(round->philos->sleep_span * 1000);
		round->last_meal_n = time_now();
	}
	while (1)
	{
		usleep(100);
		partake(round);
		_layout(round, SLEEP);
		usleep(round->philos->sleep_span * 1000);
		_layout(round, THINK);
	}
	return (NULL);
}

void	init_simulation(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->n_philos)
	{
		table->philos[i].t_creation = time_now();
		// printf("%ld\n", table->philos[i].t_creation);
		table->philos[i].circles = i;
		table->order = i + 1;
		pthread_mutex_init(&table->forks[i], NULL);
		pthread_mutex_init(table[i].philos->layout, NULL);
		pthread_mutex_init(table[i].last_meal, NULL);
		if (i == table[i].n_philos - 1)
			pthread_mutex_init(&table[i].forks[0], NULL);
		else
			pthread_mutex_init(&table[i].forks[i + 1], NULL);
		if (table[i].philos->circles > 0)
			pthread_mutex_init(&table[i].circle_n[i], NULL);
		if (pthread_create(&table[i].thread, NULL, &routine, (void *)&table[i]))
			_kill("Error creating thread");
	}
}