/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_get_and_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:02:37 by anarama           #+#    #+#             */
/*   Updated: 2024/08/09 12:36:02 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	save_get_value(pthread_mutex_t *mutex, int *value)
{
	int temp;

	safe_handle_mutex(mutex, LOCK);
	temp = *value;
	safe_handle_mutex(mutex, UNLOCK);
	return (temp);
}

void	save_set_value(pthread_mutex_t *mutex, int *value, int new_value)
{
	safe_handle_mutex(mutex, LOCK);
	*value = new_value;
	safe_handle_mutex(mutex, UNLOCK);
}