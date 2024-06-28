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

void	vars_init(t_philo *philo)
{
	philo->num_philos = 0;
	philo->time_to_die = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
}

bool	convert_args(t_philo *philo, char **arg)
{
	vars_init(philo);
	if (is_digit(arg[1]))
		philo->num_philos = _to_size_t(arg[1]);
	else
		return (false);
	if (is_digit(arg[2]))
		philo->time_to_die = _to_size_t(arg[2]);
	else
		return (false);
	if (is_digit(arg[3]))
		philo->time_to_eat = _to_size_t(arg[3]);
	else
		return (false);
	if (is_digit(arg[4]))
		philo->time_to_sleep = _to_size_t(arg[4]);
	else
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (printf("Allocation Error\n"), 1);
		if (!convert_args(philo, av))
			return (printf("Error\n"), 1);
	}
	else
		printf("\033[0;33mUsage: ./philo [number_of_philosophers]" 
			"[time_to_die] [time_to_eat] [time_to_sleep]\033[0;33m\n");
	return (0);
}
