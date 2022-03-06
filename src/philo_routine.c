/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:49:10 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/06 17:26:26 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	change_status(t_philo *philo, t_status new_status);
static int	philo_eat(t_philo *philo);
static int	philo_sleep(t_philo *philo);

void	*philo_routine(void	*philo_void)
{
	t_philo	*philo;

	philo = (t_philo *) philo_void;
	philo->last_meal = get_time_now();
	if (!philo_eat(philo))
		return (NULL);
	if (philo_sleep(philo))
		return (NULL);
	return (NULL);
}

static int	philo_eat(t_philo *philo)
{
	int	time_eating;

	if (philo->rules.time_to_die < philo->rules.time_to_eat)
		time_eating = philo->rules.time_to_die;
	else
		time_eating = philo->rules.time_to_eat;
	philo->last_meal = get_time_now();
	change_status(philo, EATING);
	usleep(time_eating * MILLI_TO_MICRO);
	if (time_eating != philo->rules.time_to_eat)
	{
		change_status(philo, DEAD);
		return (0);
	}
	return (1);
}

static int	philo_sleep(t_philo *philo)
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
		change_status(philo, SLEEPING);
		usleep(time_asleep * MILLI_TO_MICRO);
	}
	if (time_asleep != philo->rules.time_to_sleep)
	{
		change_status(philo, DEAD);
		return (0);
	}
	else
		change_status(philo, THINKING);
	return (1);
}

static void	change_status(t_philo *philo, t_status new_status)
{
	char	*msg;

	if (new_status == THINKING)
		msg = MSG_THINKING;
	if (new_status == SLEEPING)
		msg = MSG_SLEEPING;
	if (new_status == EATING)
		msg = MSG_EATING;
	if (new_status == HAS_FORK)
		msg = MSG_HAS_FORK;
	if (new_status == DEAD)
		msg = MSG_DEAD;
	philo->status = new_status;
	printf("%d %d %s\n", get_time_now(), philo->id, msg);
}
