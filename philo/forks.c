/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:35:47 by anarama           #+#    #+#             */
/*   Updated: 2024/07/31 15:17:49 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_two_forks(t_philo *philo, int left_fork, int right_fork)
{
	if (philo->philo_index % 2 == 0)
	{
		pick_up_right_fork(philo, right_fork);
		pick_up_left_fork(philo, left_fork);
	}
	else if (philo->philo_index % 2 == 1)
	{
		pick_up_left_fork(philo, left_fork);
		pick_up_right_fork(philo, right_fork);
	}
}

void	pick_up_left_fork(t_philo *philo, int left_fork)
{
	pthread_mutex_lock(&philo->forks[left_fork]);
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->time_since_last_meal, philo->philo_index, "has taken left fork");
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	pick_up_right_fork(t_philo *philo, int right_fork)
{
	pthread_mutex_lock(&philo->forks[right_fork]);
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->time_since_last_meal, philo->philo_index, "has taken right fork");
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	put_down_left_fork(t_philo *philo, int left_fork)
{
	pthread_mutex_unlock(&philo->forks[left_fork]);
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->time_since_last_meal, philo->philo_index, "has put left fork down");
	pthread_mutex_unlock(&philo->data->print_mutex);
	philo->has_left_fork = 0;
}

void	put_down_right_fork(t_philo *philo, int right_fork)
{
	pthread_mutex_unlock(&philo->forks[right_fork]);
	pthread_mutex_lock(&philo->data->print_mutex);
	print_action(philo->time_since_last_meal, philo->philo_index, "has put right fork down");
	pthread_mutex_unlock(&philo->data->print_mutex);
	philo->has_right_fork = 0;
}