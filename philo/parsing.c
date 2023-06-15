/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:46:44 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/15 03:36:17 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int argc)
{
	if (argc != 5 && argc != 6)
		return (_kill("Wrong argument input\n\tImplementation:\n\t\"./philo  [n_philos] \
 [death_span] [meal_span]  [sleep_span]  [circles](optional)\""));
	return (SUCCESS);
}

int	recheck(t_parse *parse, char **argv)
{
	parse->ph_count = _atoi(argv[1]);
	if (!parse->ph_count)
		return (_kill("Invalid number of philosophers"));
	parse->death_span = _atoi(argv[2]);
	if (!parse->death_span)
		return (_kill("Invalid time to die"));
	parse->meal_span = _atoi(argv[3]);
	if (!parse->meal_span)
		return (_kill("Invalid time to eat"));
	parse->sleep_span = _atoi(argv[4]);
	if (!parse->sleep_span)
		return (_kill("Invalid time to sleep"));
	if (argv[5])
	{
		parse->circles = _atoi(argv[5]);
		if (!parse->circles)
			return (_kill("Invalid number of circles"));
	}
	return (SUCCESS);
}

void	philos_info(int argc, char **argv, t_table *table)
{
	table->philos->death_span = _atoi(argv[2]);
	table->philos->meal_span = _atoi(argv[3]);
	table->philos->sleep_span = _atoi(argv[4]);
	if (argc == 6)
	{
		table->round_m = _calloc(sizeof(pthread_mutex_t), 1);
		table->round = _atoi(argv[5]);
		table->philos->rounds = _atoi(argv[5]);
	}
	else
		table->philos->rounds = -1;
}

t_table	*parse_and_init(int argc, char **argv)
{
	int				i;
	t_parse			parse;
	t_table			*table;
	pthread_mutex_t	*fork;

	i = -1;
	if (check_args(argc) || recheck(&parse, argv))
		return (NULL);
	fork = _calloc(sizeof(pthread_mutex_t), _atoi(argv[1]));
	table = _calloc(sizeof(t_table), _atoi(argv[1]));
	while (++i < _atoi(argv[1]))
	{
		table[i].forks = fork;
		table[i].recent_mx = _calloc(sizeof(pthread_mutex_t), 1);
		table[i].philos = _calloc(sizeof(t_philo), 1);
		table[i].philos->ph_count = _atoi(argv[1]);
		table[i].philos->layout = _calloc(sizeof(pthread_mutex_t), 1);
		philos_info(argc, argv, &table[i]);
	}
	return (table);
}
