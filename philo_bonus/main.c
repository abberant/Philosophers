/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:54:53 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/17 05:34:56 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	pid_t	*PID;

	if (parse(argc, argv))
		return (FAILURE);
	PID = init_table(argc, argv);
	if (!PID)
		_kill("Error: PID system anomaly");
	hold_processes(PID, _atoi(argv[1]));
	return (SUCCESS);
}