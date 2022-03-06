/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:25:25 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/05 18:45:57 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_table(t_table *table)
{
	int	i;

	if (table->forks)
	{
		i = 0;
		while (i < table->rules.num_philo)
		{
			pthread_mutex_destroy(&table->forks[i].lock);
			i++;
		}
		free(table->forks);
	}
	if (table->philos)
		free(table->philos);
	return (1);
}
