/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:37:51 by anarama           #+#    #+#             */
/*   Updated: 2024/07/30 21:09:36 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	print_action(philo->time_since_last_meal, philo->philo_index, "is sleeping");
	usleep(philo->data->time_to_sleep);
	philo->time_since_last_meal += philo->data->time_to_sleep;
	philo->have_eaten = 0;
}

void	philo_think(t_philo *philo)
{
	print_action(philo->time_since_last_meal, philo->philo_index, "is thinking");
	usleep(philo->data->time_to_sleep);
	philo->time_since_last_meal += philo->data->time_to_sleep;
	philo->have_slept = 0;
}

void	philo_eat(t_philo *philo)
{
	print_action(philo->time_since_last_meal, philo->philo_index, "is eating");
	usleep(philo->data->time_to_eat);
	philo->time_since_last_meal += philo->data->time_to_eat;
	philo->meals++;
	philo->have_eaten = 1;
}
