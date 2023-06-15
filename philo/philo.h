/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:16:08 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/15 03:36:36 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAILURE 1

# define SLEEP "is sleeping\n"
# define EAT "is eating\n"
# define THINK "is thinking\n"
# define DIE "died\n"
# define FORK "has taken a fork\n"

typedef struct s_parse
{
	int	ph_count;
	int	circles;
	int	death_span;
	int	meal_span;
	int	sleep_span;
}	t_parse;

typedef struct s_philo
{
	int				ph_count;
	int				rounds;
	int				death_span;
	int				meal_span;
	int				sleep_span;
	long			t_creation;
	pthread_mutex_t	*layout;
}	t_philo;

typedef struct s_table
{
	int				order;
	int				round;
	long			recent_meal;
	pthread_t		thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*round_m;
	pthread_mutex_t	*recent_mx;
	t_philo			*philos;
}	t_table;

/*#--------- UTILS ---------#*/

int		_kill(char *reason);
int		_strlen(char *str);
void	*_calloc(size_t count, size_t size);
int		_atoi(char *str);

/*#--------- PARSING ---------#*/

t_table	*parse_and_init(int argc, char **argv);

/*#--------- ROUTINE ---------#*/

void	philo_sleep(t_table *ph);
void	philo_think(t_table *ph);
void	philo_eat(t_table *ph);
void	take_fork(t_table *ph);
void	philo_dead(t_table *ph);

/*#--------- INITIALISATION ---------#*/

int		init_simulation(t_table *table);
int		monitor(t_table *table);

/*#--------- TIME ---------#*/

long	time_now(void);
void	ft_usleep(long time);

#endif
