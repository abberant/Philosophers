/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:29:34 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/12 01:46:57 by aanouari         ###   ########.fr       */
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
	ft_usleep(ph->philos->sleep_span);
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
	printf("%ld %d %s", time, ph->order, TAKE_FORK);
	pthread_mutex_unlock(ph->philos->layout);
}

void	put_fork(t_table *ph)
{
	long	time;

	time = time_now() - ph->philos->t_creation;
	pthread_mutex_lock(ph->philos->layout);
	printf("%ld %d %s", time, ph->order, PUT_FORK);
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
