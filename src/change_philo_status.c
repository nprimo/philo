/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_philo_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:10:32 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/07 16:12:48 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_philo_status(t_philo *philo, t_status new_status)
{
	philo->status = new_status;
	printf("%d %d %s\n", get_time_now(), philo->id, table()->msg[new_status]);
}
