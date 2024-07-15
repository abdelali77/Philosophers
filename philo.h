/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:59:22 by abmahfou          #+#    #+#             */
/*   Updated: 2024/06/09 20:23:37 by abmahfou         ###   ########.fr       */
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

typedef struct s_data t_data;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}				t_fork;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	long		meals_eaten;
	bool		is_full;
	long		last_meal_time; // time passed from last meal ⌚
	t_fork		*left_fork;
	t_fork		*right_fork;
	t_data		*data;
}	t_philo;

struct s_data
{
	size_t	nbr_philos;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	long	meals_needed; // the last param || flag if -1
	size_t	start_simulation;
	bool	end_simulation;
	t_fork	*forks; // Array of all the forks
	t_philo	*philos; // Array of all the philos
};


bool	is_digit(char *s);
size_t	_to_size_t(char *time);

#endif