/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:56:55 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/17 05:35:29 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

/*---------- INCLUDES ----------*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <signal.h>

/*---------- BINARY ----------*/

# define SUCCESS 0
# define FAILURE 1

/*---------- MESSAGES ----------*/

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIE "died"

/*---------- STRUCTS ----------*/

typedef struct s_philo
{
	int				ph_count;
	int				rounds;
	int				death_span;
	int				meal_span;
	int				sleep_span;
	long			t_created;
	sem_t			*fork;
	sem_t			*layout;
}				t_philo;

typedef struct s_table
{
	int				order;
	int				round;
	long			recent_meal;
	sem_t 			*recent_ms;
	t_philo			*philos;
}					t_table;

/*---------- UTILS ----------*/

int		is_valid(long num);
void	_kill(char *reason);
int		_strlen(char *str);
void	*_calloc(size_t count, size_t size);
int		_atoi(char *str);

/*---------- INITIALIZATION ----------*/

int		parse(int argc, char **argv);
pid_t	*init_table(int argc, char **argv);

/*---------- ACTIONS ----------*/

void	philo_sleep(t_table *pb);
void	philo_think(t_table *pb);
void	take_fork(t_table *pb);
void	philo_eat(t_table *pb);
void	partake(t_table *pb);

/*---------- TIME ----------*/

void	ft_usleep(long time);
long	time_now(void);

/*---------- ROUTINE ----------*/

void	life_cycle(t_table *pb);
void	hold_processes(pid_t *PID, int count);

#endif