/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 01:16:08 by aanouari          #+#    #+#             */
/*   Updated: 2023/05/28 04:57:08 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

# define SUCCESS 1
# define FAILURE 0

typedef struct s_philo
{
	int				circles;
	int				meal_span;
	int				sleep_span;
	int				death_span;
	long			t_creation;
	pthread_mutex_t	*layout;
}	t_philo;

typedef struct s_table
{
	size_t			n_philos;
	pthread_t		thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*last_meal;
	pthread_mutex_t	*circle_n;
	t_philo			*philos;
}	t_table;

/*#--------- UTILS ---------#*/

int		_kill(char *reason);
int		_strlen(char *str);
void	*_calloc(size_t count, size_t size);
int		_atoi(char *str);

/*#--------- PARSING ---------#*/

t_table	*parse_and_init(int argc, char **argv);

#endif