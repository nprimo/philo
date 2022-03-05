/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:25:01 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/05 17:55:23 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_rules	rules;
	t_fork	*forks;

	if (ac == 5 || ac == 6)
	{
		printf("Run simulation\n");
		rules = init_rules(ac, av);
		forks = init_forks(rules.num_philo);
	}
	else
		printf("Run ./philo with 4 or 5 args!\n");
	return (0);
}
