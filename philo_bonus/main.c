/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:54:53 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/15 23:54:29 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (parse(argc, argv))
		return (FAILURE);
	table = init_table(argv);
	if (!table)
		return (FAILURE);
	return (SUCCESS);
}