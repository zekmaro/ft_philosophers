/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:14:11 by anarama           #+#    #+#             */
/*   Updated: 2024/08/10 18:36:57 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_simulation()
{
	exit(EXIT_FAILURE);
}

void	delay_full_philo(t_philo *philo)
{
	if (philo->time_since_last_meal <= philo->data->time_to_die / 2)
	{
		usleep(philo->data->time_to_sleep / 2 * 1000);
		philo->time_since_last_meal += philo->data->time_to_sleep / 2;
		philo->timestamp += philo->data->time_to_sleep / 2;
	}
}

void	wait_for_all_philos(t_philo	*philo)
{
	while (save_get_value(&philo->data->stop_mutex,
		&philo->data->all_philos_ready) != 1)
	{
		usleep(10 * 1000);
	}
}

void	*philo_lifecycle(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	left_fork = philo->philo_index - 1;
	right_fork = philo->philo_index % philo->data->num_of_philos;
	save_set_value(&philo->data->stop_mutex, &philo->is_ready, 1);
	wait_for_all_philos(philo);
	get_current_time(&philo->time0);
	while (1)
	{
		get_two_forks(philo, left_fork, right_fork);
		philo_eat(philo);
		get_current_time(&philo->time0);
		put_down_right_fork(philo, right_fork);
		put_down_left_fork(philo, left_fork);
		philo_sleep(philo);
		check_dead(philo);
		delay_full_philo(philo);
		// if (philo->time_since_last_meal > philo->data->time_to_die / 2)
		// {
		// 	continue ; 
		// }
		check_dead(philo);
		if (philo->data->num_meals != -1
		&& philo->meals >= philo->data->num_meals)
			break ;
	}
	return (NULL);
}