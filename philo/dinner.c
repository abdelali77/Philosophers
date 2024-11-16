/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:49:05 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 12:48:59 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *data)
{
	(void)data;
	printf("i'm thread\n");
	return (NULL);
}

void	wait_philosophers(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philos)
		thread_handle(&data->philos[i].thread, routine, NULL, JOIN);
}

void	dinner_start(t_data *data)
{
	int	i;

	i = -1;
	if (data->nbr_philos == 1)
		routine(data);
	else
	{
		while (++i < data->nbr_philos)
			thread_handle(&data->philos[i].thread, routine, &data->philos[i], CREATE);
	}
}
