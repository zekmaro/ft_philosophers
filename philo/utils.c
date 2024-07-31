/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:56:36 by anarama           #+#    #+#             */
/*   Updated: 2024/07/31 19:58:32 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_elapsed_time(struct timeval *start, struct timeval *end) 
{
    return (end->tv_sec - start->tv_sec) * 1000
		+ (end->tv_usec - start->tv_usec) / 1000;
}

void	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->timestamp, philo->philo_index, "died");
	pthread_mutex_unlock(&philo->data->print_mutex);
	stop_simulation();
}

void	check_dead(t_philo *philo)
{
	if (philo->time_since_last_meal >= philo->data->time_to_die)
	{
		philo_dead(philo);
	}
}

void get_current_time(struct timeval *time) 
{
    gettimeofday(time, NULL);
}
