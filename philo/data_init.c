/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:14:09 by abmahfou          #+#    #+#             */
/*   Updated: 2024/09/03 17:37:51 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine()
{
	printf("thread created\n");
	return NULL;
}

bool	philo_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		data->philos[i].philo_id = i;
		data->philos[i].is_full = false;
		data->philos[i].meals_eaten = 0;
		pthread_create(&data->philos[i].thread, NULL, &routine, NULL);
		pthread_join(data->philos[i].thread, NULL);
	}
	return (true);
}

bool	data_init(t_data *data)
{
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
		pthread_mutex_init(&data->forks[i].fork, NULL);
	}
	philo_init(data);
	return (true);
}
