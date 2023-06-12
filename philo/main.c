/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:15:38 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/12 02:41:45 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	table = parse_and_init(argc, argv);
	if (!table)
		return (FAILURE);
	if (init_simulation(table))
		return(SUCCESS);
	printf("Simulation ended\n");
	return (0);
}