/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:37:51 by anarama           #+#    #+#             */
/*   Updated: 2024/08/23 12:54:04 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_time_since_last_meal(t_philo *philo)
{
	long	elapsed_time;
	int		time_since_last_meal;

	get_current_time(&philo->time1);
	elapsed_time = get_elapsed_time(&philo->time0, &philo->time1);
	time_since_last_meal = safe_get_value(&philo->data->stop_mutex,
			&philo->time_since_last_meal);
	safe_set_value(&philo->data->stop_mutex, &philo->time_since_last_meal,
		time_since_last_meal + elapsed_time);
	philo->time0 = philo->time1;
}

void	custom_usleep(t_philo *philo, int sleep_chunck, int sleep_time)
{
	while (sleep_time > 0)
	{
		usleep(sleep_chunck * 1000);
		update_time_since_last_meal(philo);
		if (check_dead(philo))
			return ;
		sleep_time -= sleep_chunck;
	}
	update_time_since_last_meal(philo);
}

void	philo_sleep(t_philo *philo)
{
	safe_print_action(philo, "is sleeping");
	custom_usleep(philo, philo->data->time_to_sleep / 10,
		philo->data->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	safe_print_action(philo, "is thinking");
	if (philo->data->num_of_philos % 2 == 1)
	{
		if (safe_get_value(&philo->data->stop_mutex,
				&philo->time_since_last_meal)
			<= 2 * philo->data->time_to_die / 3)
			custom_usleep(philo, philo->data->time_to_sleep / 10,
				philo->data->time_to_sleep);
	}
}

void	philo_eat(t_philo *philo)
{
	int	safe_num_meals;

	get_current_time(&philo->time0);
	safe_print_action(philo, "is eating");
	custom_usleep(philo, philo->data->time_to_eat / 10,
		philo->data->time_to_eat);
	safe_set_value(&philo->data->stop_mutex,
		&philo->time_since_last_meal, 0);
	get_current_time(&philo->time0);
	safe_num_meals = safe_get_value(&philo->data->stop_mutex,
			&philo->meals);
	safe_set_value(&philo->data->stop_mutex,
		&philo->meals, safe_num_meals + 1);
}
