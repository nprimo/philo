/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:10:48 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/28 18:53:16 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	void	*obj;

	obj = malloc(size * count);
	if (!obj)
		return (NULL);
	ft_bzero(obj, count * size);
	return (obj);
}

static void	ft_bzero(void *s, size_t n)
{
	memset(s, 0, n);
}
