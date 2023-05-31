/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:46:44 by aanouari          #+#    #+#             */
/*   Updated: 2023/05/30 05:52:49 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int argc)
{
	if (argc < 5 || argc > 6)
		return (_kill("Wrong argument input\n\tImplementation:\n\t\"./philo  [n_philos] \
 [death_span] [meal_span]  [sleep_span]  [circles](optional)\""));
	return (SUCCESS);
}

void	philos_info(int argc, char **argv, t_table *table)
{
	table->philos->death_span = _atoi(argv[2]);
	table->philos->meal_span = _atoi(argv[3]);
	table->philos->sleep_span = _atoi(argv[4]);
	if (argc == 6)
	{
		table->circle_n = _calloc(sizeof(pthread_mutex_t), 1);
		table->philos->circles = _atoi(argv[5]);
	}
	else
		table->philos->circles = -1;
}

t_table	*parse_and_init(int argc, char **argv)
{
	int				i;
	t_table			*table;
	pthread_mutex_t	*make_forks;
	pthread_mutex_t	*layout;

	i = -1;
	if (check_args(argc))
		return (NULL);
	table = _calloc(sizeof(t_table), _atoi(argv[1]));
	make_forks = _calloc(sizeof(pthread_mutex_t), _atoi(argv[1]));
	layout = _calloc(sizeof(pthread_mutex_t), 1);
	while (++i < _atoi(argv[1]))
	{
		table[i].n_philos = _atoi(argv[1]);
		table[i].philos = _calloc(sizeof(t_philo), 1);
		table[i].forks = make_forks;
		table[i].philos->layout = layout;
		table[i].last_meal = _calloc(sizeof(pthread_mutex_t), 1);
		philos_info(argc, argv, &table[i]);
	}
	return (table);
}
