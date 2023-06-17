/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:29:34 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/17 01:36:22 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_table *ph)
{
	long	time;

	time = time_now() - ph->philos->t_creation;
	pthread_mutex_lock(ph->philos->layout);
	printf("%ld %d %s", time, ph->order, SLEEP);
	pthread_mutex_unlock(ph->philos->layout);
}

void	philo_think(t_table *ph)
{
	long	time;

	time = time_now() - ph->philos->t_creation;
	pthread_mutex_lock(ph->philos->layout);
	printf("%ld %d %s", time, ph->order, THINK);
	pthread_mutex_unlock(ph->philos->layout);
}

void	take_fork(t_table *ph)
{
	long	time;

	time = time_now() - ph->philos->t_creation;
	pthread_mutex_lock(ph->philos->layout);
	printf("%ld %d %s", time, ph->order, FORK);
	pthread_mutex_unlock(ph->philos->layout);
}

void	philo_eat(t_table *ph)
{
	long	time;

	time = time_now() - ph->philos->t_creation;
	pthread_mutex_lock(ph->philos->layout);
	printf("%ld %d %s", time, ph->order, EAT);
	pthread_mutex_unlock(ph->philos->layout);
}

void	partake(t_table *ph)
{
	if (ph->philos->rounds > 0 && !ph->round)
		return ;
	pthread_mutex_lock(&ph->forks[ph->order - 1]);
	take_fork(ph);
	pthread_mutex_lock(&ph->forks[ph->order % ph->philos->ph_count]);
	take_fork(ph);
	philo_eat(ph);
	if (ph->philos->rounds > 0)
	{
		pthread_mutex_lock(ph->round_m);
		ph->round--;
		pthread_mutex_unlock(ph->round_m);
	}
	pthread_mutex_lock(ph->recent_mx);
	ph->recent_meal = time_now();
	pthread_mutex_unlock(ph->recent_mx);
	ft_usleep(ph->philos->meal_span);
	pthread_mutex_unlock(&ph->forks[ph->order - 1]);
	pthread_mutex_unlock(&ph->forks[ph->order % ph->philos->ph_count]);
}
