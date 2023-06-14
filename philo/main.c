/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:15:38 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/14 17:46:24 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = parse_and_init(argc, argv);
	if (!table)
		return (FAILURE);
	printf("Number of philosophers: %d\n", table->philos->ph_count);
	printf("Time to die: %d\n", table->philos->death_span);
	printf("Time to eat: %d\n", table->philos->meal_span);
	printf("Time to sleep: %d\n", table->philos->sleep_span);
	if (table->philos->circles != -1)
		printf("Number of circles: %d\n", table->philos->circles);
	// if (init_simulation(table))
	// 	return (FAILURE);
	// if (fetch_death(table))
	// 	return (FAILURE);
	return (SUCCESS);
}