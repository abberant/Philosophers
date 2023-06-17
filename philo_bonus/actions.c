/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 02:00:13 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/17 05:43:11 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	philo_sleep(t_table *pb)
{
	long	time;

	time = time_now() - pb->philos->t_created; 
	sem_wait(pb->philos->layout);
	printf("%ld %d %s\n", time, pb->order, SLEEP);
	sem_post(pb->philos->layout);
}

void	philo_think(t_table *pb)
{
	long	time;

	time = time_now() - pb->philos->t_created; 
	sem_wait(pb->philos->layout);
	printf("%ld %d %s\n", time, pb->order, THINK);
	sem_post(pb->philos->layout);
}

void	take_fork(t_table *pb)
{
	long	time;

	time = time_now() - pb->philos->t_created; 
	sem_wait(pb->philos->layout);
	printf("%ld %d %s\n", time, pb->order, FORK);
	sem_post(pb->philos->layout);
}

void	philo_eat(t_table *pb)
{
	long	time;

	time = time_now() - pb->philos->t_created; 
	sem_wait(pb->philos->layout);
	printf("%ld %d %s\n", time, pb->order, EAT);
	sem_post(pb->philos->layout);
}

void	partake(t_table *pb)
{
	sem_wait(pb->philos->fork);
	take_fork(pb);
	sem_wait(pb->philos->fork);
	take_fork(pb);
	philo_eat(pb);
	if (pb->philos->rounds > 0 && pb->round)
		pb->round--;
	if (pb->round == 0)
	{
		sem_post(pb->philos->fork);
		sem_post(pb->philos->fork);
		exit(0);
	}
	sem_wait(pb->recent_ms);
	pb->recent_meal = time_now();
	sem_post(pb->recent_ms);
	ft_usleep(pb->philos->meal_span);
	sem_post(pb->philos->fork);
	sem_post(pb->philos->fork);
}
