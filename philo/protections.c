/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:07:53 by anarama           #+#    #+#             */
/*   Updated: 2024/08/08 21:36:14 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
}

static void	handle_mutex_error(int status)
{
	if (status == EAGAIN)
		print_error("Failure initialising another mutex.");
	else if (status == ENOMEM)
		print_error("Insufficient memory exists to initialise the mutex.");
	else if (status == EPERM)
		print_error("The caller does not have the privilege to perform the operation.");
	else if (status == EBUSY)
		print_error("A previously initialised, but not yet destroyed, mutex.");
	else if (status == EINVAL)
		print_error("The value specified by mutex is invalid.");
	else
		return ;
	exit(EXIT_FAILURE);
}

static void	handle_thread_error(int status, t_mode_thread mode)
{
	if (status == EAGAIN)
		print_error("Insufficient resources to create another thread.");
	else if (status == EINVAL && mode == CREATE)
		print_error("Invalid settings in attr.");
	else if (status == EPERM)
		print_error("No permission specified in attr.");
	else if (status == EDEADLK)
		print_error("A  deadlock  was  detected");
	else if (status == EINVAL && mode == JOIN)
		print_error("Thread is not a joinable thread.");
	else if (status == ESRCH)
		print_error("No thread with the ID thread could be found.");
	else
		return ;
	exit(EXIT_FAILURE);
}

void	safe_handle_mutex(pthread_mutex_t *mutex, t_mode_mutex mode)
{
	if (mode == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL));
	else if (mode == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex));
	else if (mode == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex));
	else if (mode == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex));
}

void	safe_handle_thread(pthread_t *thread, void *(*start_routine) (void *),
				void *arg, t_mode_thread mode)
{
	if (mode == CREATE)
		handle_thread_error(pthread_create(thread, NULL, start_routine, arg), mode);
	else if (mode == JOIN)
		handle_thread_error(pthread_join(*thread, NULL), mode);
}