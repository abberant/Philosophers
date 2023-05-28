/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:03:10 by aanouari          #+#    #+#             */
/*   Updated: 2023/05/28 05:33:04 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	_norm(char c)
{
	if (c)
		_kill("Valid numerical input is required!");
}

int	_kill(char *reason)
{
	if (!reason)
		return (FAILURE);
	write(2, reason, _strlen(reason));
	write(2, "\n", 1);
	return (FAILURE);
}

int	_strlen(char *str)
{
	int	index;

	index = 0;
	while (str && str[index])
		index++;
	return (index);
}

void	*_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*tab;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	tab = (unsigned char *) malloc(size * count);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count * size)
		tab[i++] = 0;
	return ((void *) tab);
}

int	_atoi(char *str)
{
	int				i;
	unsigned long	num;

	i = -1;
	num = 0;
	while ((str[++i] >= 9 && str[i] <= 13) || str[i] == 32)
		;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		if (str[i++] == '-')
			_kill("Input must be strictly positive!");
	if (!str[i])
		_kill("Valid numerical input is required!");
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - 48;
		if (num > 9223372036854775807)
			return (-1);
	}
	_norm(str[i]);
	return (num);
}