/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:22:07 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/06 17:56:46 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_simulation(void)
{
	int			i;

	i = 0;
	while (i < table()->rules.num_philo)
	{
		if (pthread_create(&table()->philos[i].tid,
				NULL, philo_routine, &table()->philos[i]) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < table()->rules.num_philo)
	{
		if (pthread_join(table()->philos[i].tid, NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}
