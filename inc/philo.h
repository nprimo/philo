/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:23:54 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/05 18:14:39 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct s_rules {
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_meals_to_eat;
}	t_rules;

typedef struct s_fork {
	bool			is_taken;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_table {
	t_rules		rules;
	t_fork		*forks;
}	t_table;

/*---	General Purpose	---*/
int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);

/*---	Set up			---*/
t_rules	init_rules(int ac, char **av);
t_fork	*init_forks(int num_philos);
void	init_table(int ac, char **av, t_table *table);

#endif
