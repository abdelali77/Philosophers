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

void	convert_args(t_data *data, char **arg, int ac)
{
	data->meals_needed = -1;
	data->nbr_philos = _to_size_t(arg[1]);
	data->time_to_die = _to_size_t(arg[2]);
	data->time_to_eat = _to_size_t(arg[3]);
	data->time_to_sleep = _to_size_t(arg[4]);
	if (ac == 6)
		data->meals_needed = _to_size_t(arg[5]);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 5 || ac == 6)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return(1);
		if (!check_args(av))
			return (printf("Error\n"), 1);
		convert_args(data, av, ac);
	}
	else
		printf("\033[0;33mUsage: ./philo [number_of_philosophers]"
			   "[time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]\033[0;33m\n");
	return (0);
}
