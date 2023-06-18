/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 22:54:53 by aanouari          #+#    #+#             */
/*   Updated: 2023/06/18 04:21:06 by aanouari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	unlink_semaphores(void)
{
	sem_unlink("fork");
	sem_unlink("layout");
	sem_unlink("recent_ms");
}

int	main(int argc, char **argv)
{
	pid_t	*proc;

	unlink_semaphores();
	if (parse(argc, argv))
		return (FAILURE);
	proc = init_table(argc, argv);
	if (!proc)
		_kill("Error: PID system anomaly");
	hold_processes(proc, _atoi(argv[1]));
	return (SUCCESS);
}
