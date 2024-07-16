/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:56:33 by abmahfou          #+#    #+#             */
/*   Updated: 2024/06/09 20:18:26 by abmahfou         ###   ########.fr       */
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

size_t	_to_size_t(char *time)
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

bool	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!is_digit(av[i]))
			return (false);
		i++;
	}
	return (true);
}
