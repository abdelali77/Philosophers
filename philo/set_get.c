/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:28:13 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/17 10:28:13 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_bool(pthread_mutex_t *mtx, bool *bol, bool value)
{
	pthread_mutex_lock(mtx);
	*bol = value;
	pthread_mutex_unlock(mtx);
}

bool    get_bool(pthread_mutex_t *mtx, bool *bol)
{
	bool	ret_val;

	pthread_mutex_lock(mtx);
	ret_val = *bol;
	pthread_mutex_unlock(mtx);
	return (ret_val);
}

void	set_long(pthread_mutex_t *mtx, long *bol, long value)
{
	pthread_mutex_lock(mtx);
	*bol = value;
	pthread_mutex_unlock(mtx);
}

long	get_long(pthread_mutex_t *mtx, long *bol)
{
	long ret_val;

	pthread_mutex_lock(mtx);
	ret_val = *bol;
	pthread_mutex_unlock(mtx);
	return (ret_val);
}

bool	finish_simulation(t_data *data)
{
	return (get_bool(&data->end_sml_mtx, &data->end_simulation));
}
