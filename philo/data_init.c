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

bool	convert_args(t_data *data, char **arg, int ac)
{
	data->meals_needed = -1;
	if (_ft_atol(arg[1]) <= 0)
		return (false);
	data->nbr_philos = _ft_atol(arg[1]);
	if (_ft_atol(arg[2]) <= 0)
		return (false);
	data->time_to_die = _ft_atol(arg[2]);
	if (_ft_atol(arg[3]) <= 0)
		return (false);
	data->time_to_eat = _ft_atol(arg[3]);
	if (_ft_atol(arg[4]) <= 0)
		return (false);
	data->time_to_sleep = _ft_atol(arg[4]);
	if (ac == 6)
	{
		if (_ft_atol(arg[5]) < 0)
			return (false);
		data->meals_needed = _ft_atol(arg[5]);
	}
	return (true);
}

void	philo_init(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < data->nbr_philos)
	{
		philo = data->philos + i;
		philo->data = data;
		philo->philo_id = i + 1;
		philo->meals_counter = 0;
		philo->is_full = false;
		philo->last_eat_time = get_curr_time();
		pthread_mutex_init(&philo->last_eat_mtx, NULL);
		pthread_mutex_init(&philo->full_mtx, NULL);
		philo->left_fork = &data->forks[i];
		if (i == data->nbr_philos - 1)
			philo->right_fork = &data->forks[0];
		else
			philo->right_fork = &data->forks[i + 1];
		i++;
	}
}

bool	data_init(t_data *data)
{
	int	i;

	i = 0;
	data->end_simulation = false;
	data->sync_philos = false;
	data->start_simulation = 0;
	pthread_mutex_init(&data->sync_mtx, NULL);
	pthread_mutex_init(&data->end_sml_mtx, NULL);
	pthread_mutex_init(&data->print_mtx, NULL);
	data->philos = malloc(data->nbr_philos * sizeof(t_philo));
	if (!data->philos)
		return (printf("Malloc ERROR\n"), false);
	data->forks = malloc(data->nbr_philos * sizeof(t_fork));
	if (!data->forks)
		return (printf("Malloc ERROR\n"), false);
	while (i < data->nbr_philos)
	{
		pthread_mutex_init(&data->forks[i].fork, NULL);
		i++;
	}
	philo_init(data);
	return (true);
}
