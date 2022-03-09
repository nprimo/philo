/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_all_alive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:15:41 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/09 15:22:18 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	are_all_alive(t_philo *philo)
{
	bool	all_alive;

	all_alive = false;
	if (pthread_mutex_lock(&table()->status.lock) == 0)
	{
		all_alive = table()->status.all_alive;
		if (pthread_mutex_unlock(&table()->status.lock) == 0)
			return (all_alive);
	}
	philo->status = ERROR;
	return (false);
}
