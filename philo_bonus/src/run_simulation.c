/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:09:42 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/14 16:35:18 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	start_routine(int pid, int i);

int	run_simulation(void)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < table()->rules.num_philo && pid != 0)
	{
		pid = fork();
		if (!start_routine(pid, i))
			return (0);
		i++;
	}
	if (pid != 0)
	{
		i = 0;
		while (i < table()->rules.num_philo)
		{
			printf("Wait for process %d\n", table()->philos_pid[i]);
			i++;
		}
	}
	return (1);
}

static int	start_routine(int pid, int i)
{
	if (pid == -1)
		return (0);
	if (pid != 0)
	{
		table()->philos_pid[i] = pid;
		printf("pid philo[%d]: %d\n",
			i, table()->philos_pid[i]);
	}
	else
		printf("Run philo_routine for philo %d \n", i);
	return (1);
}
