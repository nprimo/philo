/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:26:25 by nprimo            #+#    #+#             */
/*   Updated: 2022/02/28 15:27:37 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	char_to_num(char c);
static int	ft_isspace(char c);
static int	ft_isalpha(char c);

int	ft_atoi(char *str)
{
	int	num;
	int	sign;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isalpha(*str))
	{
		num = num * 10 + char_to_num(*str);
		str++;
	}
	return (num * sign);
}

static int	ft_isspace(char c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}

static int	ft_isalpha(char c)
{
	return (c >= '0' && c <= '9');
}

static int	char_to_num(char c)
{
	return (c - '0');
}

/*
int main()
{
	printf("%d\n", ft_atoi("234"));
	printf("%d\n", ft_atoi("  - 234"));
	printf("%d\n", ft_atoi("-234"));
	printf("%d\n", ft_atoi("+-234"));
}
*/
