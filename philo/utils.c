/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:56:36 by anarama           #+#    #+#             */
/*   Updated: 2024/08/21 17:41:42 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_elapsed_time(struct timeval *start, struct timeval *end)
{
	return ((end->tv_sec - start->tv_sec) * 1000
		+ (end->tv_usec - start->tv_usec) / 1000);
}

void	get_current_time(struct timeval *time)
{
	gettimeofday(time, NULL);
}

void	delay_even_philos(t_philo *philo)
{
	if (philo->data->num_of_philos % 2 == 0)
		usleep(10);
}
