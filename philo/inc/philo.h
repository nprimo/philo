/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprimo <nprimo@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:23:54 by nprimo            #+#    #+#             */
/*   Updated: 2022/03/14 19:00:01 by nprimo           ###   ########.fr       */
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

# define MILLI_TO_MICRO	1000

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

typedef struct s_fork {
	bool			is_taken;
	pthread_mutex_t	lock;
}	t_fork;

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
	pthread_t		tid;
	int				last_meal;
	int				n_meals;
	t_philo_status	status;
	t_rules			rules;
	t_fork			*forks[2];
}	t_philo;

typedef struct e_table_status {
	bool			all_alive;
	int				philos_with_min_meals;
	pthread_mutex_t	lock;
}	t_table_status;

typedef struct s_table {
	t_rules			rules;
	t_fork			*forks;
	t_philo			*philos;
	char			*msg[5];
	int				time_at_start;
	pthread_mutex_t	lock_print;
	t_table_status	status;
}	t_table;

/*---	General Purpose	---*/
int		ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);

/*---	Time function	---*/
int		gettimeofday_in_ms(void);
int		get_time_now(void);

/*---	Table & Setup	---*/
t_table	*table(void);
int		init_table(int ac, char **av);

/*---	Routine			---*/
int		run_simulation(void);
void	philo_try_to_eat(t_philo *philo);
void	*philo_routine(void	*philo_void);
void	update_philo_status(t_philo *philo, t_philo_status new_status);
int		get_time_activity(t_philo *philo, int time_for_activity);

/*---	Philos check	---*/
bool	are_all_alive(t_philo *philo);
bool	have_all_min_meals(t_philo *philo);

/*---	Cleaning		---*/
int		free_table(void);

#endif
