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
	mutex_handle(mtx, LOCK);
	*bol = value;
	mutex_handle(mtx, UNLOCK);
}

bool    get_bool(pthread_mutex_t *mtx, bool *bol)
{
	bool	ret_val;

	mutex_handle(mtx, LOCK);
	ret_val = *bol;
	mutex_handle(mtx, UNLOCK);
	return (ret_val);
}

void	set_long(pthread_mutex_t *mtx, long *bol, long value)
{
	mutex_handle(mtx, LOCK);
	*bol = value;
	mutex_handle(mtx, UNLOCK);
}

long	get_long(pthread_mutex_t *mtx, long *bol)
{
	long ret_val;

	mutex_handle(mtx, LOCK);
	ret_val = *bol;
	mutex_handle(mtx, UNLOCK);
	return (ret_val);
}

bool	finish_simulation(t_data *data)
{
	return (get_bool(&data->end_sml_mtx, &data->end_simulation));
}
