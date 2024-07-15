/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:59:13 by abmahfou          #+#    #+#             */
/*   Updated: 2024/06/09 20:27:56 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	vars_init(t_data *data)
{
	data->nbr_philos = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
}

bool	convert_args(t_data *data, char **arg)
{
	vars_init(data);
	if (is_digit(arg[1]))
		data->nbr_philos = _to_size_t(arg[1]);
	else
		return (false);
	if (is_digit(arg[2]))
		data->time_to_die = _to_size_t(arg[2]);
	else
		return (false);
	if (is_digit(arg[3]))
		data->time_to_eat = _to_size_t(arg[3]);
	else
		return (false);
	if (is_digit(arg[4]))
		data->time_to_sleep = _to_size_t(arg[4]);
	if (is_digit(arg[5]))
		data->meals_needed = _to_size_t(arg[5]);
	else
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	data;
	if (ac == 5 || ac == 6)
	{
		if (!convert_args(&data, av))
			return (printf("Error\n"), 1);
	}
	else
		printf("\033[0;33mUsage: ./philo [number_of_philosophers]" 
			"[time_to_die] [time_to_eat] [time_to_sleep]\033[0;33m\n");
	printf("%zu %zu %zu %zu %zu\n", data.nbr_philos, data.time_to_die, data.time_to_eat, data.time_to_sleep, data.meals_needed);
	return (0);
}
