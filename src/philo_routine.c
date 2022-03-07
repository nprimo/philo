/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:49:10 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/07 12:48:49 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*change_status(t_philo *philo, t_status new_status);
static int	get_fork(t_fork *fork, t_philo *philo);
// static int	drop_fork(t_fork *fork);
static int	philo_eat(t_philo *philo);
static int	philo_sleep(t_philo *philo);

void	*philo_routine(void	*philo_void)
{
	t_philo	*philo;

	philo = (t_philo *) philo_void;
	philo->last_meal = get_time_now();
	change_status(philo, THINKING);
	while ((get_time_now() - philo->last_meal) < philo->rules.time_to_die)
	{
		if (get_fork(philo->forks[philo->first_fork], philo) == 1
			&& get_fork(philo->forks[philo->second_fork], philo) == 1)
		{
			if (!philo_eat(philo))
				return (change_status(philo, DEAD));
			if (!philo_sleep(philo))
				return (change_status(philo, DEAD));
			change_status(philo, THINKING);
		}
	}
	change_status(philo, DEAD);
	return (NULL);
}

static int	get_fork(t_fork *fork, t_philo *philo)
{
	int		got_fork;

	got_fork = 0;
	if (pthread_mutex_lock(&fork->lock) == 0)
	{
		if (fork->is_taken == false)
		{
			fork->is_taken = true;
			change_status(philo, HAS_FORK);
			got_fork = 1;
		}
		if (pthread_mutex_unlock(&fork->lock) == 0)
			return (got_fork);
		else
			return (-1);
	}
	return (-1);
}

// static int	drop_fork(t_philo *philo, int id_fork)
// {
// 	if (pthread_mutex_lock(&philo->forks[id_fork]->lock) == 0)
// 	{
// 		if (philo->forks[id_fork]->is_taken == true)
// 		{
// 			philo->forks[id_fork]->is_taken = false;
// 		}
// 		if (pthread_mutex_unlock(&philo->forks[id_fork]->lock) == 0)
// 			return (1);
// 		else
// 			return (-1);
// 	}
// 	return (-1);
// }

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
		return (0);
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
		return (0);
	return (1);
}

static void	*change_status(t_philo *philo, t_status new_status)
{
	philo->status = new_status;
	printf("%d %d %s\n", get_time_now(), philo->id, table()->msg[new_status]);
	return (NULL);
}
