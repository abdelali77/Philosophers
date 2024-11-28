/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 20:41:08 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/22 20:41:08 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_died(t_philo *philo)
{
	long	elap;

	if (get_bool(&philo->full_mtx, &philo->is_full))
		return (false);
	elap = get_curr_time() - get_long(&philo->last_eat_mtx,
			&philo->last_eat_time);
	if (elap >= philo->data->time_to_die)
		return (true);
	return (false);
}

bool	all_philos_ate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philos)
	{
		if (!get_bool(&data->philos[i].full_mtx, &data->philos[i].is_full))
			return (false);
		i++;
	}
	return (true);
}

void	ft_monitor(t_data *data)
{
	int		i;

	while (!finish_simulation(data))
	{
		i = 0;
		while (i < data->nbr_philos)
		{
			if (is_died(&data->philos[i]))
			{
				set_bool(&data->end_sml_mtx, &data->end_simulation, true);
				ft_print_status(&data->philos[i], DEAD);
				return ;
			}
			if (!finish_simulation(data) && all_philos_ate(data))
			{
				set_bool(&data->end_sml_mtx, &data->end_simulation, true);
				return ;
			}
			i++;
		}
	}
}
