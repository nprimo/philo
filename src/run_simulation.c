/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:22:07 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/06 15:22:41 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	run_simulation(t_table *table)
{
	pthread_t	*tid;
	int			i;

	tid = ft_calloc(table->rules.num_philo, sizeof(pthread_t));
	if (!tid)
		return (0);
	i = 0;
	while (i < table->rules.num_philo)
	{
		pthread_create(&tid[i], NULL, philo_routine, &table->philos[i]);
		i++;
	}
	i = 0;
	while (i < table->rules.num_philo)
	{
		pthread_join(tid[i], NULL);
		i++;
	}
	return (1);
}
