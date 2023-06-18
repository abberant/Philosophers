/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 23:00:47 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/18 04:24:53 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	is_valid(long num)
{
	if (num > 2147483647)
		return (SUCCESS);
	if (num <= 0)
		return (SUCCESS);
	return (num);
}

void	_kill(char *reason)
{
	if (!reason)
		_kill("Error");
	write(2, reason, _strlen(reason));
	write(2, "\n", 1);
	exit(FAILURE);
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
	int				sign;
	unsigned long	num;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
		if (num > 9223372036854775807 && sign == 1)
			return (-1);
		if (num > 9223372036854775807 && sign == -1)
			return (0);
	}
	if (str[i])
		return (0);
	return (is_valid(num * sign));
}
