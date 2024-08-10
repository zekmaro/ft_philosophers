/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:35:47 by anarama           #+#    #+#             */
/*   Updated: 2024/08/10 18:34:51 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_two_forks(t_philo *philo, int left_fork, int right_fork)
{
	long elapsed_time;

	if (philo->meals > 0)
		philo_think(philo);
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
	get_current_time(&philo->time1);
	elapsed_time = get_elapsed_time(&philo->time0, &philo->time1);
	if (elapsed_time >= philo->data->time_to_die)
		philo_dead(philo);
}

void	pick_up_left_fork(t_philo *philo, int left_fork)
{
	safe_handle_mutex(&philo->forks[left_fork], LOCK);
	save_print_action(philo, "has taken left fork");
}

void	pick_up_right_fork(t_philo *philo, int right_fork)
{
	safe_handle_mutex(&philo->forks[right_fork], LOCK);
	save_print_action(philo, "has taken right fork");
}

void	put_down_left_fork(t_philo *philo, int left_fork)
{
	safe_handle_mutex(&philo->forks[left_fork], UNLOCK);
	save_print_action(philo, "has put left fork down");
}

void	put_down_right_fork(t_philo *philo, int right_fork)
{
	safe_handle_mutex(&philo->forks[right_fork], UNLOCK);
	save_print_action(philo, "has put right fork down");
}
