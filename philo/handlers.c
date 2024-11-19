/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:52:50 by abmahfou          #+#    #+#             */
/*   Updated: 2024/11/16 11:50:45 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_handle(pthread_mutex_t *mutex, t_op op)
{
	if (op == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return (printf("Mutex Error\n"), 1);
	}
	else if (op == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			return (printf("Mutex Error\n"), 1);
	}
	else if (op == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			return (printf("Mutex Error\n"), 1);
	}
	else if (op == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			return (printf("Mutex Error\n"), 1);
	}
	else
		printf("Wrong code MUTEX\n");
	return (0);
}

int	thread_handle(pthread_t *thrd, void *(*start_routine)(void *),
			void *data, t_op op)
{
	if (op == CREATE)
	{
		if (pthread_create(thrd, NULL, start_routine, data) != 0)
			return (printf("Thread Error\n"), 1);
	}
	else if (op == JOIN)
	{
		if (pthread_join(*thrd, NULL) != 0)
			return (printf("Thread Error\n"), 1);
	}
	else if (op == DETACH)
	{
		if (pthread_detach(*thrd) != 0)
			return (printf("Thread Error\n"), 1);
	}
	else
		printf("Wrong code THREAD\n");
	return (0);
}
