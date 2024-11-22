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
		philo->meals_counter = 0;
		philo->died = false;
		philo->is_full = false;
		philo->last_meal_time = get_curr_time();
		mutex_handle(&philo->last_meal_mtx, INIT);
		mutex_handle(&philo->died_mtx, INIT);
		mutex_handle(&philo->full_mtx, INIT);
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
	data->start_simulation = 0;
	mutex_handle(&data->sync_mtx, INIT);
	mutex_handle(&data->start_mtx, INIT);
	mutex_handle(&data->end_sml_mtx, INIT);
	mutex_handle(&data->print_mtx, INIT);
	mutex_handle(&data->lock, INIT);
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
