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

void	*routine_one(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	ft_usleep(philo->data->time_to_die);
	ft_print_status(philo, DEAD);
	return (NULL);
}

void	one_philo(t_data *data)
{
	if (thread_handle(&data->philos[0].thread, routine_one,
		&data->philos[0], CREATE))
		return ;
	if (thread_handle(&data->philos[0].thread,
		NULL, NULL, JOIN))
		return ;
}

void	wait_threads(t_data *data)
{
	while (1)
	{
		if (!get_bool(&data->sync_mtx, &data->sync_philos))
			break ;
	}
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(data);
	while (!finish_simulation(data))
	{
		if (philo->is_full)
			return (NULL);
		ft_eat(philo);
		ft_print_status(philo, SLEEP);
		ft_usleep(philo->data->time_to_sleep);
		ft_think(philo);
	}
	return (NULL);
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
		{
			if (thread_handle(&data->philos[i].thread, routine,
				&data->philos[i], CREATE))
				return ;
		}
	}
	data->start_simulation = get_curr_time();
	set_bool(&data->sync_mtx, &data->sync_philos, true);
	i = -1;
	while (++i < data->nbr_philos)
	{
		if (thread_handle(&data->philos[i].thread, NULL, NULL, JOIN))
			return;
	}
}
