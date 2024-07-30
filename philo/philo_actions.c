/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:37:51 by anarama           #+#    #+#             */
/*   Updated: 2024/07/30 22:29:35 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->time_since_last_meal, philo->philo_index, "is sleeping");
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_sleep);
	philo->time_since_last_meal += philo->data->time_to_sleep;
	philo->have_eaten = 0;
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->time_since_last_meal, philo->philo_index, "is thinking");
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_sleep);
	philo->time_since_last_meal += philo->data->time_to_sleep;
	philo->have_slept = 0;
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->time_since_last_meal, philo->philo_index, "is eating");
	pthread_mutex_unlock(&philo->data->print_mutex);
	usleep(philo->data->time_to_eat);
	philo->time_since_last_meal += philo->data->time_to_eat;
	philo->meals++;
	philo->have_eaten = 1;
}
