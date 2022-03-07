/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_try_to_eat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:34:07 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/07 16:15:00 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	get_fork(t_fork *fork, t_philo *philo);
static void	drop_fork(t_fork *fork, t_philo *philo);
static void	philo_eat(t_philo *philo);

void	philo_try_to_eat(t_philo *philo)
{
	if (get_fork(philo->forks[0], philo))
	{
		change_philo_status(philo, HAS_FORK);
		if (get_fork(philo->forks[1], philo))
		{
			change_philo_status(philo, HAS_FORK);
			philo_eat(philo);
		}
	}
	drop_fork(philo->forks[0], philo);
	drop_fork(philo->forks[1], philo);
}

static bool	get_fork(t_fork *fork, t_philo *philo)
{
	if (!pthread_mutex_lock(&fork->lock))
	{
		if (fork->is_taken == false)
			fork->is_taken = true;
		if (!pthread_mutex_unlock(&fork->lock))
			return (fork->is_taken);
	}
	philo->status = ERROR;
	return (0);
}

static void	drop_fork(t_fork *fork, t_philo *philo)
{
	if (!pthread_mutex_lock(&fork->lock))
	{
		if (fork->is_taken == true)
			fork->is_taken = false;
		if (!pthread_mutex_unlock(&fork->lock))
			return ;
	}
	philo->status = ERROR;
}

static void	philo_eat(t_philo *philo)
{
	int	time_eating;

	if (philo->rules.time_to_die < philo->rules.time_to_eat)
		time_eating = philo->rules.time_to_die;
	else
		time_eating = philo->rules.time_to_eat;
	philo->last_meal = get_time_now();
	change_philo_status(philo, EATING);
	usleep(time_eating * MILLI_TO_MICRO);
}
