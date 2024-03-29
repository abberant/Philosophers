/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:15:06 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/17 01:36:57 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long time)
{
	long	start;

	start = time_now();
	while (time_now() - start < time)
		usleep(10);
}

void	*routine(void *ph)
{
	t_table	*table;

	table = ph;
	table->recent_meal = time_now();
	if (!(table->order % 2))
	{
		ft_usleep(table->philos->meal_span);
		table->recent_meal = time_now();
	}
	while (1)
	{
		usleep(10);
		partake(table);
		philo_sleep(table);
		ft_usleep(table->philos->meal_span);
		philo_think(table);
	}
	return (NULL);
}

int	init_simulation(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philos->ph_count)
	{
		table[i].order = i + 1;
		table[i].philos->t_creation = time_now();
		pthread_mutex_init(&table->forks[i], NULL);
		pthread_mutex_init(table[i].recent_mx, NULL);
		pthread_mutex_init(table[i].philos->layout, NULL);
		if (table[i].philos->rounds > 0)
			pthread_mutex_init(table[i].round_m, NULL);
		if (pthread_create(&table[i].thread, NULL, &routine, &table[i]))
			return (_kill("Error creating threads!"));
	}
	return (SUCCESS);
}
