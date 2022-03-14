/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_activity.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:38:00 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/07 16:43:07 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_activity(t_philo *philo, int time_for_activity)
{
	int	time_left_alive;

	time_left_alive = philo->rules.time_to_die
		- (get_time_now() - philo->last_meal);
	if (time_left_alive > time_for_activity)
		return (time_for_activity);
	else
		return (time_left_alive);
}
