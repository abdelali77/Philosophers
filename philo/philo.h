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
# define RESET "\033[0m"
# define BOLD "\033[1m"

typedef struct s_data	t_data;

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

typedef enum e_status
{
	THINK,
	SLEEP,
	EAT,
	DEAD,
	TAKE,
}			e_status;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}				t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	long			meals_counter;
	bool			is_full;
	bool			died;
	long			last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	died_mtx;
	pthread_mutex_t	last_meal_mtx;
	pthread_mutex_t	full_mtx;
	t_data			*data;
}	t_philo;

struct s_data
{
	int				nbr_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_needed;
	long			start_simulation;
	bool			end_simulation;
	bool			sync_philos;
	pthread_t		monitor;
	pthread_mutex_t	sync_mtx;
	pthread_mutex_t start_mtx;
	pthread_mutex_t	end_sml_mtx;
	pthread_mutex_t	print_mtx;
	t_fork			*forks;
	t_philo			*philos;
};

bool	convert_args(t_data *data, char **arg, int ac);
long	_ft_atol(char *time);
bool	data_init(t_data *data);
int		mutex_handle(pthread_mutex_t *mutex, t_op op);
int		thread_handle(pthread_t *thrd, void *(*routine)(void *),
			void *data, t_op op);
int		ft_usleep(size_t milliseconds);
long	get_curr_time(void);
void	ft_print_status(t_philo *philo, e_status status);
void	dinner_start(t_data *data);
void	set_bool(pthread_mutex_t *mtx, bool *bol, bool value);
bool	get_bool(pthread_mutex_t *mtx, bool *bol);
void	set_long(pthread_mutex_t *mtx, long *bol, long value);
long	get_long(pthread_mutex_t *mtx, long *bol);
bool 	finish_simulation(t_data *data);
void	ft_eat(t_philo *philo);
void	ft_think(t_philo *philo);
void	*ft_monitor(void *data);

#endif