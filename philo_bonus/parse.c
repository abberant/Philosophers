/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:52:18 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/15 23:58:12 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	parse(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (_kill("Wrong argument input\n\tImplementation:\n\t\"./philo  [n_philos] \
 [death_span] [meal_span]  [sleep_span]  [circles](optional)\""));
	if (!_atoi(argv[1]))
		return (_kill("Invalid number of philosophers"));
	if (!_atoi(argv[2]))
		return (_kill("Invalid time to die"));
	if (!_atoi(argv[3]))
		return (_kill("Invalid time to eat"));
	if (!_atoi(argv[4]))
		return (_kill("Invalid time to sleep"));
	if (argc == 6 && !_atoi(argv[5]))
		return (_kill("Invalid number of circles"));
	return (SUCCESS);
}

int	init_table(char **argv)
{
	int		i;
	t_table *pb;

	i = -1;
	pb = _calloc(sizeof(t_table), 1);
	
	return (pb);
}