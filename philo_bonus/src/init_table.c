/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:49:46 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/14 14:03:28 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static t_rules	init_rules(int ac, char **av);

int	init_table(int ac, char **av)
{
	(table()->rules) = init_rules(ac, av);
	(table()->philos_pid) = malloc(sizeof(pid_t) * table()->rules.num_philo);
	if (!table()->philos_pid)
		return (0);
	table()->status.all_alive = true;
	(table()->msg[THINKING]) = MSG_THINKING;
	(table()->msg[SLEEPING]) = MSG_SLEEPING;
	(table()->msg[EATING]) = MSG_EATING;
	(table()->msg[HAS_FORK]) = MSG_HAS_FORK;
	(table()->msg[DEAD]) = MSG_DEAD;
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
