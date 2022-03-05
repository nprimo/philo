/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:51:15 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/05 18:01:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*init_forks(int num_philos)
{
	t_fork	*forks;

	forks = ft_calloc(num_philos, sizeof(t_fork));
	if (!forks)
		return (NULL);
	return (forks);
}
