/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:37:51 by anarama           #+#    #+#             */
/*   Updated: 2024/08/19 17:59:19 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_time_since_last_meal(t_philo *philo)
{
	long elapsed_time;

	get_current_time(&philo->time1);
	elapsed_time = get_elapsed_time(&philo->time0, &philo->time1);
	save_set_value(&philo->data->stop_mutex, &philo->time_since_last_meal,
		philo->time_since_last_meal + elapsed_time);
	philo->time0 = philo->time1;
}

void	custom_usleep(t_philo *philo, int sleep_chunck, int	sleep_time)
{
	while (sleep_time)
	{
		usleep(sleep_chunck * 1000);
		update_time_since_last_meal(philo);
		sleep_time -= sleep_chunck;
	}
}

void	philo_sleep(t_philo *philo)
{
	int sleep_chunck = 10;
	int	sleep_time = philo->data->time_to_sleep;

	save_print_action(philo, "is sleeping");
	custom_usleep(philo, sleep_chunck, sleep_time);
}

void	philo_think(t_philo *philo)
{
	save_print_action(philo, "is thinking");
}

void	philo_eat(t_philo *philo)
{
	int	save_num_meals;

	get_current_time(&philo->time0);
	save_print_action(philo, "is eating");
	custom_usleep(philo, 10, philo->data->time_to_sleep);
	save_set_value(&philo->data->stop_mutex,
		&philo->time_since_last_meal, 0);
	get_current_time(&philo->time0);
	save_num_meals = save_get_value(&philo->data->stop_mutex,
		&philo->meals);
	save_set_value(&philo->data->stop_mutex,
		&philo->meals, save_num_meals + 1);
}
