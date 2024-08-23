/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:56:36 by anarama           #+#    #+#             */
/*   Updated: 2024/08/23 17:45:55 by anarama          ###   ########.fr       */
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

void	define_chuncks(t_data *data)
{
	if (data->time_to_eat >= 10)
		data->eat_chunck = 10;
	else if (data->time_to_eat < 10)
		data->eat_chunck = data->time_to_eat;
	if (data->time_to_sleep >= 10)
		data->sleep_chunck = 10;
	else if (data->time_to_sleep < 10)
		data->sleep_chunck = data->time_to_sleep;
}
