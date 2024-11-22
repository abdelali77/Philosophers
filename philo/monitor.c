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
	if (elap >= philo->data->time_to_die)
	{
		ft_print_status(philo, DEAD);
		return (true);
	}
	return (false);
}

bool	all_philos_ate(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
	{
		if (data->meals_needed <= data->philos[i].meals_counter)
			set_bool(&data->philos[i].full_mtx, &data->philos[i].is_full, true);
	}
	i = -1;
	while (++i < data->nbr_philos)
	{
		if (!get_bool(&data->philos[i].full_mtx, &data->philos[i].is_full))
			return (false);
	}
	return (true);
}

void	ft_monitor(void *data)
{
	t_data	*dt;
	int		i;

	dt = (t_data *)data;
	while (1)
	{
		i = -1;
		while (++i < dt->nbr_philos)
		{
			if (is_died(&dt->philos[i]) || all_philos_ate(dt))
				return ;
		}
	}
}
