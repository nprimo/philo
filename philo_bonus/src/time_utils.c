/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:40:15 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/14 16:42:29 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	gettimeofday_in_ms(void);

int	get_time_now(void)
{
	static int	time_start = 0;
	int			time_now;

	if (time_start == 0)
		time_start = gettimeofday_in_ms();
	time_now = gettimeofday_in_ms();
	return (time_now - time_start);
}

static int	gettimeofday_in_ms(void)
{
	struct timeval	now;
	int				now_msec;

	if (gettimeofday(&now, NULL) == 0)
		now_msec = now.tv_sec * 1000 + now.tv_usec / 1000;
	else
		now_msec = 0;
	return (now_msec);
}
