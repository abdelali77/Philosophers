/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:59:13 by abmahfou          #+#    #+#             */
/*   Updated: 2024/09/02 16:51:12 by abmahfou         ###   ########.fr       */
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
		if (_ft_atol(arg[5]) <= 0)
			return (false);
		data->meals_needed = _ft_atol(arg[5]);
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 5 || ac == 6)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (1);
		if (!convert_args(data, av, ac))
			return (printf("Error\n"), 1);
		if (!data_init(data))
			return (1);
	}
	else
		printf("\033[0;33mUsage: ./philo [number_of_philosophers]"
			"[time_to_die] [time_to_eat] [time_to_sleep]"
			"[number_of_times_each_philosopher_must_eat]\033[0;33m\n");
	return (0);
}
