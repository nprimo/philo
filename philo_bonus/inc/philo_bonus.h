/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:44:45 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/14 16:42:24 by nprimo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <limits.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define MSG_THINKING "is thinking"
# define MSG_SLEEPING "is sleeping"
# define MSG_EATING "is eating"
# define MSG_HAS_FORK "has taken a fork"
# define MSG_DEAD "died"

typedef struct s_rules {
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_meals_to_eat;
}	t_rules;

typedef enum e_philo_status {
	THINKING = 0,
	SLEEPING,
	EATING,
	HAS_FORK,
	DEAD,
	ERROR
}	t_philo_status;

typedef struct s_philo {
	int				id;
	pid_t			pid;
	int				last_meal;
	int				n_meals;
	t_philo_status	status;
	t_rules			rules;
}	t_philo;

typedef struct s_table_status {
	bool			all_alive;
	int				philos_with_min_meals;
	pthread_mutex_t	lock;
}	t_table_status;

typedef struct s_table {
	t_rules			rules;
	pid_t			*philos_pid;
	char			*msg[5];
	t_table_status	status;
}	t_table;

/*---	General Purpose	---*/
int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);

/*---	Time function	---*/
int		get_time_now(void);

/*---	Table & Setup	---*/
int		init_table(int ac, char **av);
t_table	*table(void);

/*---	Simulation		---*/
int		run_simulation(void);

/*---	Cleaning		---*/
int		free_table(void);

#endif