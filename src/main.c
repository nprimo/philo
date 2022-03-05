/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:25:01 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/05 18:22:11 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		table = setup_table();
		printf("Run simulation\n");
		if (!init_table(ac, av, &table))
			return (free_table(&table));
	}
	else
		printf("Run ./philo with 4 or 5 args!\n");
	return (0);
}
