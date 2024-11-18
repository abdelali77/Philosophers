/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:56:33 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 12:50:14 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	_ft_atol(char *time)
{
	int		i;
	long	res;

	i = 0;
	res = 0;
	if (time[i] == '+')
		i++;
	while (time[i])
	{
		if (!(time[i] >= '0' && time[i] <= '9'))
			return (-1);
		res = res * 10 + (time[i] - '0');
		i++;
	}
	if (res > INT_MAX)
		return (-1);
	return (res);
}

long	get_curr_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_curr_time();
	while ((get_curr_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
