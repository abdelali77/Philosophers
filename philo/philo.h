/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:59:22 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 13:07:25 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

# define RED "\033[1;31m"
# define YELLOW "\033[0;33m"

typedef struct s_data	t_data;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}				t_fork;

typedef enum e_op
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
	CREATE,
	JOIN,
	DETACH,
}			t_op;

typedef struct s_philo
{
	pthread_t	thread; 
	int			philo_id;
	long		meals_eaten;
	bool		is_full;
	long		last_meal_time;
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		*data;
}	t_philo;

struct s_data
{
	int		nbr_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	meals_needed;
	long	start_simulation;
	bool	end_simulation;
	t_fork	*forks;
	t_philo	*philos;
};

long	_ft_atol(char *time);
bool	data_init(t_data *data);
void	mutex_handle(pthread_mutex_t *mutex, t_op op);
void	thread_handle(pthread_t *thrd, void *(*start_routine)(void *),
			void *data, t_op op);
int		ft_usleep(size_t milliseconds);
long	get_time(void);

#endif