/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:51:15 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/06 15:27:23 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*init_forks(int num_philos)
{
	t_fork	*forks;
	int		i;

	forks = ft_calloc(num_philos, sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(&forks[i].lock, NULL) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}
