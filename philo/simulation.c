/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:14:11 by anarama           #+#    #+#             */
/*   Updated: 2024/08/21 18:12:04 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_single_philo(t_philo *philo, int left_fork)
{
	if (philo->data->num_of_philos == 1)
	{
		pick_up_left_fork(philo, left_fork);
		usleep(philo->data->time_to_die * 1000);
		put_down_left_fork(philo, left_fork);
		update_time_since_last_meal(philo);
		return (1);
	}
	return (0);
}

void	*philo_lifecycle(void *arg)
{
	t_philo	*philo;
	int		left_fork;
	int		right_fork;

	philo = (t_philo *)arg;
	left_fork = philo->philo_index - 1;
	right_fork = philo->philo_index % philo->data->num_of_philos;
	safe_set_value(&philo->data->stop_mutex, &philo->is_ready, 1);
	get_current_time(&philo->time0);
	philo->simulation_start = philo->time0;
	if (handle_single_philo(philo, left_fork) == 1)
		return (NULL);
	while (1)
	{
		get_two_forks(philo, left_fork, right_fork);
		philo_eat(philo);
		put_down_right_fork(philo, right_fork);
		put_down_left_fork(philo, left_fork);
		philo_sleep(philo);
		if (safe_get_value(&philo->data->stop_mutex,
				&philo->data->stop_simulation) == 1)
			break ;
	}
	return (NULL);
}
