/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:23:15 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/21 12:14:47 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_died(t_philo *philo)
{
	long	elap;

	if (get_bool(&philo->full_mtx, &philo->is_full))
		return (false);
	elap = get_curr_time() - get_long(&philo->last_meal_mtx, &philo->last_meal_time);
	if (elap > philo->data->time_to_die)
		return (true);
	return (false);
}

int	all_philos_full_died(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		if (data->philos[i].meals_counter == data->meals_needed)
			data->philos[i].is_full = true;
		if (!data->philos[i].is_full)
			return (0);
	}
	i = -1;
	while (++i < data->nbr_philos)
	{
		if (data->time_to_die >= data->philos[i].last_meal_time)
			data->philos[i].died = true;
		if (data->philos[i].died)
			return (0);
	}
	return (1);
}

void	*ft_monitor(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		
	}
}
