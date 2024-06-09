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
	philo->time_die = 0;
	philo->time_eat = 0;
	philo->time_sleep = 0;
}

void	convert_args(t_philo *philo, char **arg)
{
	vars_init(philo);
	if (is_digit(arg[1]))
		philo->num_philos = _to_size_t(arg[1]);
	if (is_digit(arg[2]))
		philo->time_die = _to_size_t(arg[2]);
	if (is_digit(arg[3]))
		philo->time_eat = _to_size_t(arg[3]);
	if (is_digit(arg[4]))
		philo->time_sleep = _to_size_t(arg[4]);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			return (printf("Allocation Error\n"), 1);
		convert_args(philo, av);
	}
	else
		printf("\033[0;33mUsage: ./philo [number_of_philosophers]" 
			"[time_to_die] [time_to_eat] [time_to_sleep]\033[0;33m\n");
	return (0);
}
