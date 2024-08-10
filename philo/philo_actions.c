/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:37:51 by anarama           #+#    #+#             */
/*   Updated: 2024/08/10 18:44:57 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	custom_usleep(t_philo *philo, int sleep_chunck, int	sleep_time)
{
	long elapsed_time;

	while (sleep_time)
	{
		usleep(sleep_chunck * 1000);
		get_current_time(&philo->time1);
		elapsed_time = get_elapsed_time(&philo->time0, &philo->time1);
		if (elapsed_time >= philo->data->time_to_die)
			philo_dead(philo);
		sleep_time -= sleep_chunck;
	}
}

void	philo_sleep(t_philo *philo)
{
	int sleep_chunck = 10;
	int	sleep_time = philo->data->time_to_sleep;

	save_print_action(philo, "is sleeping");
	custom_usleep(philo, sleep_chunck, sleep_time);
	philo->time_since_last_meal += philo->data->time_to_sleep;
	philo->timestamp += philo->data->time_to_sleep;
}

void	philo_think(t_philo *philo)
{
	save_print_action(philo, "is thinking");
}

void	philo_eat(t_philo *philo)
{
	save_print_action(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	philo->timestamp += philo->data->time_to_eat;
	philo->time_since_last_meal = 0;
	philo->meals++;
}
