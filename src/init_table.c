/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:11:45 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/05 18:19:04 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(int ac, char **av, t_table *table)
{
	table->rules = init_rules(ac, av);
	table->forks = init_forks(table->rules.num_philo);
	if (!table->forks)
		return (0);
	return (1);
}
