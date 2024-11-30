/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:39:49 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/17 12:39:49 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo)
{
	if (finish_simulation(philo->data)
		|| get_bool(&philo->full_mtx, &philo->is_full))
		return ;
	pthread_mutex_lock(&philo->right_fork->fork);
	ft_print_status(philo, TAKE);
	pthread_mutex_lock(&philo->left_fork->fork);
	ft_print_status(philo, TAKE);
	philo->meals_counter++;
	ft_print_status(philo, EAT);
	ft_usleep(philo->data->time_to_eat, philo->data);
	set_long(&philo->last_eat_mtx, &philo->last_eat_time, get_curr_time());
	if (philo->data->meals_needed > 0
		&& philo->meals_counter == philo->data->meals_needed)
		set_bool(&philo->full_mtx, &philo->is_full, true);
	pthread_mutex_unlock(&philo->right_fork->fork);
	pthread_mutex_unlock(&philo->left_fork->fork);
}

void	ft_thinking(t_philo *philo)
{
	if (!finish_simulation(philo->data))
		ft_print_status(philo, THINK);
}

void	ft_sleeping(t_philo *philo)
{
	if (!finish_simulation(philo->data))
	{
		ft_print_status(philo, SLEEP);
		ft_usleep(philo->data->time_to_sleep, philo->data);
	}
}

void	ft_print_status(t_philo *philo, t_status status)
{
	long	timestamp;

	pthread_mutex_lock(&philo->data->print_mtx);
	timestamp = get_curr_time() - philo->data->start_simulation;
	if (finish_simulation(philo->data) && status != DEAD)
	{
		pthread_mutex_unlock(&philo->data->print_mtx);
		return ;
	}
	if (status == EAT)
		printf("%ld %d is eating\n", timestamp, philo->philo_id);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", timestamp, philo->philo_id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", timestamp, philo->philo_id);
	else if (status == TAKE)
		printf("%ld %d has taken a fork\n",
			timestamp, philo->philo_id);
	else if (status == DEAD)
		printf("%ld %d "RED"died"RESET"\n",
			timestamp, philo->philo_id);
	pthread_mutex_unlock(&philo->data->print_mtx);
}
