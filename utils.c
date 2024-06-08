/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:56:33 by abmahfou          #+#    #+#             */
/*   Updated: 2024/06/08 13:30:50 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_digit(char *s)
{
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (false);
		s++;
	}
	return (true);
}

size_t	convert_time(char *time)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	while (time[i])
	{
		res = res * 10 + (time[i] - '0');
		i++;
	}
	return (res);
}
