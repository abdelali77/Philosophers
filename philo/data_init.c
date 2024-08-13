/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:14:09 by abmahfou          #+#    #+#             */
/*   Updated: 2024/07/17 13:14:09 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_init(t_data *data)
{
	
}

bool	data_init(t_data *data)
{
	pthread_mutex_t	f;
	int	i;

	i = -1;
	data->end_simulation = false;
	data->philos = malloc(data->nbr_philos * sizeof(t_philo));
	if (!data->philos)
		return (false);
	data->forks = malloc(data->nbr_philos * sizeof(t_fork));
	if (!data->forks)
		return (false);
	while (++i < data->nbr_philos)
	{
		data->forks[i].fork_id = i;
		data->forks[i].fork = pthread_mutex_init(f, NULL);
	}
	philo_init(data);
	return (true);
}
