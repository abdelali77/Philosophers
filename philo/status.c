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
	if (philo->is_full || finish_simulation(philo->data))
		return ;
	mutex_handle(&philo->right_fork->fork, LOCK);
	ft_print_status(philo, TAKE);
	mutex_handle(&philo->left_fork->fork, LOCK);
	ft_print_status(philo, TAKE);
	philo->meals_counter++;
	ft_print_status(philo, EAT);
	ft_usleep(philo->data->time_to_eat, philo->data);
	set_long(&philo->last_meal_mtx, &philo->last_meal_time, get_curr_time());
	if (philo->data->meals_needed > -1 && philo->meals_counter >= philo->data->meals_needed)
		set_bool(&philo->full_mtx, &philo->is_full, true);
	mutex_handle(&philo->right_fork->fork, UNLOCK);
	mutex_handle(&philo->left_fork->fork, UNLOCK);
}

void	ft_print_status(t_philo *philo, e_status status)
{
	long	timestamp;

	if (philo->is_full || philo->data->end_simulation)
		return ;
	mutex_handle(&philo->data->print_mtx, LOCK);
	timestamp = get_curr_time() - get_long(&philo->data->start_mtx, &philo->data->start_simulation);
	if (status == EAT)
		printf("%ld %d is eating\n", timestamp, philo->philo_id);
	else if (status == SLEEP)
		printf("%ld %d is sleeping\n", timestamp, philo->philo_id);
	else if (status == THINK)
		printf("%ld %d is thinking\n", timestamp, philo->philo_id);
	else if (status == TAKE)
		printf("%ld %d has taken a fork\n", timestamp, philo->philo_id);
	else if (status == DEAD)
		printf("%ld %d "RED"died"RESET"\n", timestamp, philo->philo_id);
	mutex_handle(&philo->data->print_mtx, UNLOCK);
}
