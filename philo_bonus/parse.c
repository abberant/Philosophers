/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:52:18 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/18 04:27:54 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(long time)
{
	long	start;

	start = time_now();
	while (time_now() - start < time)
		usleep(10);
}

int	parse(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		_kill("Wrong argument input\n\tImplementation:\n\t\"./philo  [n_philos] \
 [death_span] [meal_span]  [sleep_span]  [circles](optional)\"");
	if (!_atoi(argv[1]))
		_kill("Invalid number of philosophers");
	if (!_atoi(argv[2]))
		_kill("Invalid time to die");
	if (!_atoi(argv[3]))
		_kill("Invalid time to eat");
	if (!_atoi(argv[4]))
		_kill("Invalid time to sleep");
	if (argc == 6 && !_atoi(argv[5]))
		_kill("Invalid number of rounds");
	return (SUCCESS);
}

void	philos_info(t_table *pb, int argc, char **argv, int index)
{
	pb->order = index + 1;
	pb->philos->ph_count = _atoi(argv[1]);
	pb->philos->death_span = _atoi(argv[2]);
	pb->philos->meal_span = _atoi(argv[3]);
	pb->philos->sleep_span = _atoi(argv[4]);
	if (argc == 6)
	{
		pb->philos->rounds = _atoi(argv[5]);
		pb->round = _atoi(argv[5]);
	}
	else
	{
		pb->philos->rounds = -1;
		pb->round = -1;
	}
}

pid_t	*init_table(int argc, char **argv)
{
	int		i;
	pid_t	*proc;
	t_table	pb;

	i = 0;
	proc = _calloc(sizeof(pid_t), _atoi(argv[1]));
	pb.philos = _calloc(sizeof(t_philo), 1);
	if (!pb.philos || !proc)
		_kill("Error: Memory allocation failed");
	pb.philos->fork = sem_open("fork", O_CREAT, 0666, _atoi(argv[1]));
	pb.philos->layout = sem_open("layout", O_CREAT, 0666, 1);
	if (pb.philos->fork == SEM_FAILED || pb.philos->layout == SEM_FAILED)
		_kill("Error: Semaphore creation failed");
	while (i < _atoi(argv[1]))
	{
		pb.philos->t_created = time_now();
		philos_info(&pb, argc, argv, i);
		proc[i] = fork();
		if (proc[i] < 0)
			_kill("Error: Fork failed");
		if (!proc[i])
			life_cycle(&pb);
		i++;
	}
	free(pb.philos);
	return (proc);
}
