/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:49:10 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/09 15:39:55 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_sleep(t_philo *philo);
static int	is_alive(t_philo *philo);

void	*philo_routine(void	*philo_void)
{
	t_philo	*philo;

	philo = (t_philo *) philo_void;
	philo->last_meal = get_time_now();
	update_philo_status(philo, THINKING);
	while (is_alive(philo)
		&& are_all_alive(philo)
		&& philo->status != ERROR)
	{
		if (philo->status == THINKING)
			philo_try_to_eat(philo);
		else if (philo->status == EATING)
			philo_sleep(philo);
		else if (philo->status == SLEEPING)
			update_philo_status(philo, THINKING);
	}
	if (philo->status != ERROR)
		update_philo_status(philo, DEAD);
	return (NULL);
}

static int	is_alive(t_philo *philo)
{
	if ((get_time_now() - philo->last_meal) < philo->rules.time_to_die)
		return (1);
	else
		return (0);
}

static void	philo_sleep(t_philo *philo)
{
	int	time_asleep;
	int	time_start;

	time_start = get_time_now();
	time_asleep = get_time_activity(philo, philo->rules.time_to_sleep);
	if (time_asleep > 0)
	{
		update_philo_status(philo, SLEEPING);
		while (1)
		{
			if ((get_time_now() - time_start) >= time_asleep)
				return ;
		}
	}
}
