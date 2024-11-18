/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:49:05 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 12:48:59 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_one(void *data)
{
	
}

void	one_philo(t_data *data)
{
	thread_handle(&data->philos[0].thread, routine_one, NULL, CREATE);
	thread_handle(&data->philos[0].thread, routine_one, NULL, JOIN);
}

void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	return (NULL);
}

void	wait_philosophers(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		thread_handle(&data->philos[i].thread, dinner_simulation, NULL, JOIN);
}

void	dinner_start(t_data *data)
{
	int	i;

	i = -1;
	if (data->nbr_philos == 1)
		one_philo(data);
	else
	{
		while (++i < data->nbr_philos)
			thread_handle(&data->philos[i].thread, dinner_simulation, &data->philos[i], CREATE);
	}
}
