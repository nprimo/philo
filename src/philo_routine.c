/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:49:10 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/05 18:54:23 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void	*philo_void)
{
	t_philo	*philo;

	philo = (t_philo *) philo_void;
	while (philo->status != DEAD)
	{
		if (get_forks(philo))
		{
			eat(philo);
			sleep(philo);
		}
	}
	return (NULL);
}
