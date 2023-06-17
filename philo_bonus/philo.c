/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 05:48:20 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/17 05:50:35 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	hold_processes(pid_t *PID, int count)
{
	int i;
	int	status;

	i = -1;
	while (waitpid(-1, &status, 0) == -1)
	{
		if (!WEXITSTATUS(status))
		{
			while (++i < count)
				kill(PID[i], SIGKILL);
			return ;
		}
	}
}

int	fetch_death(t_table pb)
{
	long	time;

	time = time_now() - pb.philos->t_created;
	sem_wait(pb.recent_ms);
	if (time - pb.recent_meal >= pb.philos->death_span)
	{
		sem_wait(pb.philos->layout);
		printf("%ld %d %s\n", time, pb.order, DIE);
		sem_post(pb.philos->layout);
		sem_post(pb.recent_ms);
		return (SUCCESS);
	}
	sem_post(pb.recent_ms);
	return (FAILURE);
}

void	*routine(void *param)
{
	t_table	*pb;

	pb = (t_table *)param;
	if (!pb->order % 2)
		ft_usleep(pb->philos->meal_span);
	while (1)
	{
		partake(pb);
		philo_sleep(pb);
		ft_usleep(pb->philos->sleep_span);
		philo_think(pb);
	}
	return (NULL);
}

void	life_cycle(t_table *pb)
{
	pthread_t	tid;

	pb->recent_meal = time_now();
	pb->recent_ms = sem_open("recent_ms", O_CREAT, 0644, 1);
	if (pb->recent_ms == SEM_FAILED)
		return ;
	if (pthread_create(&tid, NULL, &routine, pb))
		_kill("Error: creating thread");
	ft_usleep(15);
	while (1)
		if (!fetch_death(*pb))
			exit(0);
}