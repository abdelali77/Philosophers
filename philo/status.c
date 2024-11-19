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

void	ft_print_status(t_philo *philo, e_status status)
{
	long	timestamp;

	timestamp = get_curr_time() - philo->data->start_simulation;
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
}
