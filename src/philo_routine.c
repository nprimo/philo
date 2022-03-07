/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:49:10 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/07 16:11:44 by nprimo           ###   ########.fr       */
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
	change_philo_status(philo, THINKING);
	while (is_alive(philo) && philo->status != ERROR)
	{
		if (philo->status == THINKING)
			philo_try_to_eat(philo);
		else if (philo->status == EATING)
			philo_sleep(philo);
		else if (philo->status == SLEEPING)
			change_philo_status(philo, THINKING);
	}
	if (philo->status != ERROR)
		change_philo_status(philo, DEAD);
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
	int	time_left_to_eat;
	int	time_asleep;

	time_left_to_eat = philo->rules.time_to_die
		- (get_time_now() - philo->last_meal);
	if (time_left_to_eat > philo->rules.time_to_sleep)
		time_asleep = philo->rules.time_to_sleep;
	else if (time_left_to_eat > 0)
		time_asleep = time_left_to_eat;
	else
		time_asleep = 0;
	if (time_asleep > 0)
	{
		change_philo_status(philo, SLEEPING);
		usleep(time_asleep * MILLI_TO_MICRO);
	}
}
