/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:01:33 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/14 23:41:08 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_table ph)
{
	long	now;

	now = time_now();
	if (now - ph.recent_meal >= ph.philos->death_span)
	{
		philo_dead(&ph);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	rounds(t_table *ph)
{
	int	i;

	i = -1;
	while (++i < ph->philos->ph_count)
	{
		if (ph[i].circle > 0)
			return (SUCCESS);
	}
	return (FAILURE);
}

int	fetch_death(t_table *ph)
{
	int	i;

	while (1)
	{
		i = -1;
		ft_usleep(20);
		while (++i < ph->philos->ph_count)
			if (is_dead(ph[i]))
				return (FAILURE);
		if (ph->philos->circles > 0)
			if (rounds(ph))
				return (FAILURE);
	}
	return (SUCCESS);
}
