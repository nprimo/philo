/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:37:44 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/14 16:50:31 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_routine(int id)
{
	int time_last_meal;

	time_last_meal = get_time_now();
	while ((get_time_now() - time_last_meal) < table()->rules.time_to_die)
	{
		printf("%d %d is eating\n", get_time_now(), id);
		usleep(table()->rules.time_to_eat * 1000);
		printf("%d %d is sleeping\n", get_time_now(), id);
		usleep(table()->rules.time_to_sleep * 1000);
		printf("%d %d is thinking\n", get_time_now(), id);
	}
	return (1);
}