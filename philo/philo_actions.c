/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:37:51 by anarama           #+#    #+#             */
/*   Updated: 2024/07/31 15:11:42 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_dead(t_philo *philo)
{
	if (philo->time_since_last_meal >= philo->data->time_to_die)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		print_action(philo->timestamp, philo->philo_index, "died");
		pthread_mutex_unlock(&philo->data->print_mutex);
		stop_simulation();
	}
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->timestamp, philo->philo_index, "is sleeping");
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_sleep * 1000);
	philo->time_since_last_meal += philo->data->time_to_sleep;
	philo->timestamp += philo->data->time_to_sleep;
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->timestamp, philo->philo_index, "is thinking");
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_sleep * 1000);
	philo->time_since_last_meal += philo->data->time_to_sleep;
	philo->timestamp += philo->data->time_to_sleep;
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
	philo->have_eaten = 1;
}
