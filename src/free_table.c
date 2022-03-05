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
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
	return (1);
}
