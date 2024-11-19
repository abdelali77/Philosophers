/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:14:09 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 13:03:21 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < data->nbr_philos)
	{
		philo = data->philos + i;
		philo->data = data;
		philo->philo_id = i + 1;
		philo->meals_eaten = 0;
		philo->died = false;
		philo->is_full = false;
		philo->last_meal_time = get_curr_time();
		philo->left_fork = &data->forks[i];
		philo->right_fork = &data->forks[(i + 1) % philo->data->nbr_philos];
		if (philo->data->nbr_philos % 2 == 0)
		{
			philo->right_fork = &data->forks[i];
			philo->left_fork = &data->forks[(i + 1) % philo->data->nbr_philos];
		}
	}
	return (true);
}

bool	data_init(t_data *data)
{
	int	i;

	i = -1;
	data->end_simulation = false;
	data->sync_philos = false;
	data->philos = malloc(data->nbr_philos * sizeof(t_philo));
	if (!data->philos)
		return (printf("Malloc ERROR\n"), false);
	data->forks = malloc(data->nbr_philos * sizeof(t_fork));
	if (!data->forks)
		return (printf("Malloc ERROR\n"), false);
	while (++i < data->nbr_philos)
	{
		data->forks[i].fork_id = i;
		mutex_handle(&data->forks[i].fork, INIT);
	}
	philo_init(data);
	return (true);
}
