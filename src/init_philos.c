/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:36:45 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/05 18:46:12 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philos(t_rules rules, t_fork *forks)
{
	t_philo	*philos;
	int		id;

	philos = ft_calloc(rules.num_philo, sizeof(t_philo));
	if (!philos)
		return (NULL);
	id = 1;
	while (id <= rules.num_philo)
	{
		philos[id - 1].id = id;
		philos[id - 1].rules = rules;
		philos[id - 1].forks[0] = &forks[id - 1];
		if (id == rules.num_philo)
			philos[id - 1].forks[1] = &forks[0];
		else
			philos[id - 1].forks[1] = &forks[id];
		id++;
	}
	return (philos);
}
