/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:30:02 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/05 17:43:46 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_rules	init_rules(int ac, char **av)
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
