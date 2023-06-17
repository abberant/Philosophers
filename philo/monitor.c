/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:01:33 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/17 01:38:27 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_table ph)
{
	long	time;

	time = time_now() - ph.philos->t_creation;
	pthread_mutex_lock(ph.recent_mx);
	if (time_now() - ph.recent_meal >= ph.philos->death_span)
	{
		pthread_mutex_lock(ph.philos->layout);
		printf("%ld %d %s", time, ph.order, DIE);
		return (FAILURE);
	}
	pthread_mutex_unlock(ph.recent_mx);
	return (SUCCESS);
}

int	rounds(t_table *ph)
{
	int	i;

	i = -1;
	while (++i < ph->philos->ph_count)
	{
		pthread_mutex_lock(ph[i].round_m);
		if (ph[i].round > 0)
		{
			pthread_mutex_unlock(ph[i].round_m);
			return (SUCCESS);
		}
		pthread_mutex_unlock(ph[i].round_m);
	}
	return (FAILURE);
}

int	monitor(t_table *ph)
{
	int	i;

	while (1)
	{
		usleep(10);
		i = -1;
		while (++i < ph->philos->ph_count)
			if (is_dead(ph[i]))
				return (FAILURE);
		if (ph->philos->rounds > 0)
			if (rounds(ph))
				return (FAILURE);
	}
	return (SUCCESS);
}
