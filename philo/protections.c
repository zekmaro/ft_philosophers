/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:07:53 by anarama           #+#    #+#             */
/*   Updated: 2024/08/21 18:27:26 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
}

static int	handle_mutex_error(int status)
{
	if (status == EAGAIN)
		print_error("Failure initialising another mutex.");
	else if (status == ENOMEM)
		print_error("Insufficient memory exists to initialise the mutex.");
	else if (status == EPERM)
		print_error("The caller does not have"
			"the privilege to perform the operation.");
	else if (status == EBUSY)
		print_error("A previously initialised, but not yet destroyed, mutex.");
	else if (status == EINVAL)
		print_error("The value specified by mutex is invalid.");
	else
		return (1);
	return (0);
}

static int	handle_thread_error(int status, t_mode_thread mode)
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
		return (1);
	return (0);
}

int	safe_handle_mutex(pthread_mutex_t *mutex, t_mode_mutex mode)
{
	int	result;

	result = 1;
	if (mode == INIT)
		result = handle_mutex_error(pthread_mutex_init(mutex, NULL));
	else if (mode == LOCK)
		result = handle_mutex_error(pthread_mutex_lock(mutex));
	else if (mode == UNLOCK)
		result = handle_mutex_error(pthread_mutex_unlock(mutex));
	else if (mode == DESTROY)
		result = handle_mutex_error(pthread_mutex_destroy(mutex));
	return (result);
}

int	safe_handle_thread(pthread_t *thread, void *(*start_routine) (void *),
				void *arg, t_mode_thread mode)
{
	int	result;

	result = 1;
	if (mode == CREATE)
		result = handle_thread_error(pthread_create(thread, NULL,
					start_routine, arg), mode);
	else if (mode == JOIN)
		result = handle_thread_error(pthread_join(*thread, NULL), mode);
	return (result);
}
