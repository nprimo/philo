/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:11:45 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/14 19:00:50 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_rules	init_rules(int ac, char **av);
static t_fork	*init_forks(int num_philos);
static t_philo	*init_philos(t_rules rules, t_fork *forks);

int	init_table(int ac, char **av)
{
	(table()->rules) = init_rules(ac, av);
	table()->forks = init_forks(table()->rules.num_philo);
	if (!table()->forks)
		return (0);
	(table()->philos) = init_philos(table()->rules, table()->forks);
	if (!table()->philos)
		return (0);
	if (pthread_mutex_init(&table()->status.lock, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table()->lock_print, NULL) != 0)
		return (0);
	table()->status.all_alive = true;
	(table()->msg[THINKING]) = MSG_THINKING;
	(table()->msg[SLEEPING]) = MSG_SLEEPING;
	(table()->msg[EATING]) = MSG_EATING;
	(table()->msg[HAS_FORK]) = MSG_HAS_FORK;
	(table()->msg[DEAD]) = MSG_DEAD;
	table()->time_at_start = gettimeofday_in_ms();
	return (1);
}

static t_rules	init_rules(int ac, char **av)
{
	t_rules	rules;

	rules.num_philo = ft_atoi(av[1]);
	rules.time_to_die = ft_atoi(av[2]);
	rules.time_to_eat = ft_atoi(av[3]);
	rules.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		rules.num_meals_to_eat = ft_atoi(av[5]);
	else
		rules.num_meals_to_eat = 0;
	return (rules);
}

static t_fork	*init_forks(int num_philos)
{
	t_fork	*forks;
	int		i;

	forks = ft_calloc(num_philos, sizeof(t_fork));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(&forks[i].lock, NULL) != 0)
			return (NULL);
		i++;
	}
	return (forks);
}

static t_philo	*init_philos(t_rules rules, t_fork *forks)
{
	t_philo	*philos;
	int		id;

	philos = ft_calloc(rules.num_philo, sizeof(t_philo));
	if (!philos)
		return (NULL);
	id = 1;
	while (id <= rules.num_philo)
	{
		philos[id - 1].id = id;
		philos[id - 1].rules = rules;
		philos[id - 1].forks[0] = &forks[id - 1];
		if (id == rules.num_philo)
			philos[id - 1].forks[1] = &forks[0];
		else
			philos[id - 1].forks[1] = &forks[id];
		id++;
	}
	return (philos);
}
