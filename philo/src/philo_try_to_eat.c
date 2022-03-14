/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_try_to_eat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:34:07 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/14 18:53:16 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	get_fork(t_fork *fork, t_philo *philo);
static void	drop_fork(t_fork *fork, t_philo *philo);
static void	philo_eat(t_philo *philo);
static void	update_table_status_philos_with_min_meals(t_philo *philo);

void	philo_try_to_eat(t_philo *philo)
{
	if (get_fork(philo->forks[0], philo))
	{
		if (get_fork(philo->forks[1], philo))
		{
			update_philo_status(philo, HAS_FORK);
			update_philo_status(philo, HAS_FORK);
			philo_eat(philo);
			if (philo->n_meals == philo->rules.num_meals_to_eat)
				update_table_status_philos_with_min_meals(philo);
			drop_fork(philo->forks[1], philo);
		}
		drop_fork(philo->forks[0], philo);
	}
}

static bool	get_fork(t_fork *fork, t_philo *philo)
{
	bool	got_fork;

	got_fork = false;
	if (!pthread_mutex_lock(&fork->lock))
	{
		if (fork->is_taken == false)
		{
			fork->is_taken = true;
			got_fork = true;
		}
		if (!pthread_mutex_unlock(&fork->lock))
			return (got_fork);
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

	philo->last_meal = get_time_now();
	time_eating = get_time_activity(philo, philo->rules.time_to_eat);
	update_philo_status(philo, EATING);
	while (1)
	{
		if ((get_time_now() - philo->last_meal) >= time_eating)
		{
			philo->n_meals++;
			return ;
		}
	}
}

static void	update_table_status_philos_with_min_meals(t_philo *philo)
{
	if (pthread_mutex_lock(&table()->status.lock) == 0)
	{
		table()->status.philos_with_min_meals++;
		if (pthread_mutex_unlock(&table()->status.lock) == 0)
			return ;
	}
	philo->status = ERROR;
}
