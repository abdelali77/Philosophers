/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:59:13 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 10:23:34 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		if (!convert_args(&data, av, ac))
			return (printf("Enter a valid argument\n"), 1);
		if (!data_init(&data))
			return (ft_clean(&data), 1);
		if ((&data)->meals_needed == 0)
		{
			ft_clean(&data);
			return (printf(RED"at least one meal needed\n"RESET), 1);
		}
		simulation(&data);
		ft_clean(&data);
	}
	else
		printf(YELLOW"Usage: ./philo [number_of_philosophers]"
			"[time_to_die] [time_to_eat] [time_to_sleep]"
			"[number_of_times_each_philosopher_must_eat]\n"RESET);
	return (0);
}
