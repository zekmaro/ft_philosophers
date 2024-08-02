/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejarama <andrejarama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:37:51 by anarama           #+#    #+#             */
/*   Updated: 2024/08/02 11:19:12 by andrejarama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	long elapsed_time;
	int sleep_chunck = 10;
	int	sleep_time = philo->data->time_to_sleep;

	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->timestamp, philo->philo_index, "is sleeping");
	pthread_mutex_unlock(&philo->data->print_mutex);
	while (sleep_time)
	{
		usleep(sleep_chunck * 1000);
		get_current_time(&philo->time1);
		elapsed_time = get_elapsed_time(&philo->time0, &philo->time1);
		if (elapsed_time >= philo->data->time_to_die)
			philo_dead(philo);
		sleep_time -= sleep_chunck;
	}
	philo->time_since_last_meal += philo->data->time_to_sleep;
	philo->timestamp += philo->data->time_to_sleep;
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->timestamp, philo->philo_index, "is thinking");
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->timestamp, philo->philo_index, "is eating");
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_eat * 1000);
	philo->timestamp += philo->data->time_to_eat;
	philo->time_since_last_meal = 0;
	philo->meals++;
}
