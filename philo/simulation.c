/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:14:11 by anarama           #+#    #+#             */
/*   Updated: 2024/08/12 15:40:31 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_simulation()
{
	exit(EXIT_FAILURE);
}

void	wait_for_all_philos(t_philo	*philo)
{
	while (save_get_value(&philo->data->stop_mutex,
		&philo->data->all_philos_ready) != 1)
	{
		usleep(10 * 1000);
	}
}

void	handle_single_philo(t_philo	*philo, int	left_fork)
{
	if (philo->data->num_of_philos == 1)
	{
		pick_up_left_fork(philo, left_fork);
		usleep(philo->data->time_to_die * 1000);
		update_time_since_last_meal(philo);
		//philo->timestamp += philo->data->time_to_die;
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
	philo->simulation_start = philo->time0;
	handle_single_philo(philo, left_fork);
	while (1)
	{
		get_two_forks(philo, left_fork, right_fork);
		philo_eat(philo);
		put_down_right_fork(philo, right_fork);
		put_down_left_fork(philo, left_fork);
		philo_sleep(philo);
		if (save_get_value(&philo->data->stop_mutex,
					&philo->data->stop_simulation) == 1)
			break ;
	}
	return (NULL);
}