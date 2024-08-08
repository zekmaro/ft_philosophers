/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:56:36 by anarama           #+#    #+#             */
/*   Updated: 2024/08/08 22:39:10 by anarama          ###   ########.fr       */
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
	if (save_get_value(&philo->data->stop_mutex,
			philo->data->stop_simulation) == 0)
	{
		save_print_action(philo, "died");
		save_set_value(&philo->data->stop_mutex, &philo->data->stop_simulation, 1);
	}
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
