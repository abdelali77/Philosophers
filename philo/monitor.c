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
	while (!finish_simulation(dt))
	{
		i = -1;
		while (++i < dt->nbr_philos)
		{
			if (is_died(&dt->philos[i]))
			{
				set_bool(&dt->end_sml_mtx, &dt->end_simulation, true);
				ft_print_status(&dt->philos[i], DEAD);
				return ;
			}
			if (!finish_simulation(dt) && all_philos_ate(data))
			{
				set_bool(&dt->end_sml_mtx, &dt->end_simulation, true);
				return ;
			}
		}
	}
}
