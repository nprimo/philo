/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_all_min_meals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:35:22 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/09 16:38:25 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	have_all_min_meals(t_philo *philo)
{
	bool	have_all_min_meals;

	have_all_min_meals = false;
	if (pthread_mutex_lock(&table()->status.lock) == 0)
	{
		if (table()->status.philos_with_min_meals == table()->rules.num_philo)
			have_all_min_meals = true;
		if (pthread_mutex_unlock(&table()->status.lock) == 0)
			return (have_all_min_meals);
	}
	philo->status = ERROR;
	return (false);
}
