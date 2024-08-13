/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:35:47 by anarama           #+#    #+#             */
/*   Updated: 2024/08/13 17:25:45 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_two_forks(t_philo *philo, int left_fork, int right_fork)
{
	if (philo->meals > 0)
		philo_think(philo);
	if (philo->philo_index % 2 == 0)
	{
		pick_up_right_fork(philo, right_fork);
		update_time_since_last_meal(philo);
		pick_up_left_fork(philo, left_fork);
		update_time_since_last_meal(philo);
	}
	else if (philo->philo_index % 2 == 1)
	{
		pick_up_left_fork(philo, left_fork);
		update_time_since_last_meal(philo);
		pick_up_right_fork(philo, right_fork);
		update_time_since_last_meal(philo);
	}
}

void	pick_up_left_fork(t_philo *philo, int left_fork)
{
	safe_handle_mutex(&philo->forks[left_fork], LOCK);
	save_print_action(philo, "has taken a fork");
}

void	pick_up_right_fork(t_philo *philo, int right_fork)
{
	safe_handle_mutex(&philo->forks[right_fork], LOCK);
	save_print_action(philo, "has taken a fork");
}

void	put_down_left_fork(t_philo *philo, int left_fork)
{
	safe_handle_mutex(&philo->forks[left_fork], UNLOCK);
	//save_print_action(philo, "has put left fork down");
}

void	put_down_right_fork(t_philo *philo, int right_fork)
{
	safe_handle_mutex(&philo->forks[right_fork], UNLOCK);
	//save_print_action(philo, "has put right fork down");
}
