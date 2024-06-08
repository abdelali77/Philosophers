/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:59:13 by abmahfou          #+#    #+#             */
/*   Updated: 2024/06/08 16:31:46 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	vars_init(t_philo *philo)
{
	philo->phi = 0;
	philo->time_die = 0;
	philo->time_eat = 0;
	philo->time_sleep = 0;
}

int	main(int ac, char **av)
{
	t_philo	*st;

	if (ac == 5)
	{
		st = malloc(sizeof(t_philo));
		vars_init(st);
		if (is_digit(av[1]))
			st->phi = convert_time(av[1]);
		if (is_digit(av[2]))
			st->time_die = convert_time(av[2]);
		if (is_digit(av[3]))
			st->time_eat = convert_time(av[3]);
		if (is_digit(av[4]))
			st->time_sleep = convert_time(av[4]);
	}
	else
		printf("Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep]\n");
	return (0);
}
