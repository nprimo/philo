/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_philo_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:10:32 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/09 15:21:39 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	change_philo_status(t_philo *philo, t_philo_status new_status);
static void	print_philo_status(t_philo *philo);

void	update_philo_status(t_philo *philo, t_philo_status new_status)
{
	change_philo_status(philo, new_status);
	if (are_all_alive(philo))
		print_philo_status(philo);
}

static void	change_philo_status(t_philo *philo, t_philo_status new_status)
{
	philo->status = new_status;
}

static void	print_philo_status(t_philo *philo)
{
	printf("%d %d %s\n",
		get_time_now(), philo->id, table()->msg[philo->status]);
}
