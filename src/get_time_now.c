/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_now.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:42:58 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/01 13:33:06 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_now(void)
{
	struct timeval	now;
	int				now_msec;

	if (gettimeofday(&now, NULL) == 0)
		now_msec = now.tv_sec * 1000 + now.tv_usec / 1000;
	else
		now_msec = 0;
	return (now_msec);
}
