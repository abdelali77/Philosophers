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
	long	timestamp;

	philo = (t_philo *)data;
	timestamp = get_curr_time() - philo->data->start_simulation;
	printf("%ld %d has taken a fork\n", timestamp, philo->philo_id);
	ft_usleep(philo->data->time_to_die, philo->data);
	timestamp = get_curr_time() - philo->data->start_simulation;
	printf("%ld %d "RED"died"RESET"\n", timestamp, philo->philo_id);
	return (NULL);
}

void	one_philo(t_data *data)
{
	pthread_create(&data->philos[0].thread, NULL,
		routine_one, &data->philos[0]);
	pthread_join(data->philos[0].thread, NULL);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (finish_simulation(philo->data)
		|| get_bool(&philo->full_mtx, &philo->is_full))
		return (NULL);
	while (!get_bool(&philo->data->sync_mtx, &philo->data->sync_philos))
		;
	if (philo->philo_id % 2 == 0)
		ft_sleeping(philo);
	while (!finish_simulation(philo->data))
	{
		ft_eat(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

void	simulation(t_data *data)
{
	int	i;

	i = -1;
	if (data->nbr_philos == 1)
	{
		data->start_simulation = get_curr_time();
		one_philo(data);
		return ;
	}
	else
	{
		data->start_simulation = get_curr_time();
		while (++i < data->nbr_philos)
			pthread_create(&data->philos[i].thread, NULL,
				routine, &data->philos[i]);
		set_bool(&data->sync_mtx, &data->sync_philos, true);
	}
	ft_monitor(data);
	i = -1;
	while (++i < data->nbr_philos)
		pthread_join(data->philos[i].thread, NULL);
}
