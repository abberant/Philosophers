/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:56:55 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/15 23:52:47 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

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

# define SUCCESS 0
# define FAILURE 1

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
	int				t_created;
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
int		_kill(char *reason);
int		_strlen(char *str);
void	*_calloc(size_t count, size_t size);
int		_atoi(char *str);

/*---------- INITIALIZATION ----------*/

int		parse(int argc, char **argv);

#endif