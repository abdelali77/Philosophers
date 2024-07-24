/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:14:09 by abmahfou          #+#    #+#             */
/*   Updated: 2024/07/17 13:14:09 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_data *data)
{
	int	i;

	i = -1;
	data->end_simulation = false;
	data->philos = malloc(data->nbr_philos * sizeof(t_philo));
	// PROTECT MALLOC !!
	data->forks = malloc(data->nbr_philos * sizeof(t_fork));
	// PROTECT MALLOC !!
	while (++i < data->nbr_philos)
	{
		/* code */
		data->forks[i].fork_id = i;
	}
}