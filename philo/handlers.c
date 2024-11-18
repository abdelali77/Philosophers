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

void	mutex_handle(pthread_mutex_t *mutex, t_op op)
{
	if (op == INIT)
	{
		if (pthread_mutex_init(mutex, NULL) != 0)
			return ((void)printf("Mutex Error\n"));
	}
	else if (op == LOCK)
	{
		if (pthread_mutex_lock(mutex) != 0)
			return ((void)printf("Mutex Error\n"));
	}
	else if (op == UNLOCK)
	{
		if (pthread_mutex_unlock(mutex) != 0)
			return ((void)printf("Mutex Error\n"));
	}
	else if (op == DESTROY)
	{
		if (pthread_mutex_destroy(mutex) != 0)
			return ((void)printf("Mutex Error\n"));
	}
	else
		printf("Wrong code MUTEX\n");	
}

void	thread_handle(pthread_t *thrd, void *(*start_routine)(void *),
			void *data, t_op op)
{
	if (op == INIT)
	{
		if (pthread_create(thrd, NULL, start_routine, data) != 0)
			return ((void)printf("Thread Error\n"));
	}
	else if (op == JOIN)
	{
		if (pthread_join(*thrd, NULL) != 0)
			return ((void)printf("Thread Error\n"));
	}
	else if (op == DETACH)
	{
		if (pthread_detach(*thrd) != 0)
			return ((void)printf("Thread Error\n"));
	}
	else
		printf("Wrong code THREAD\n");
}
