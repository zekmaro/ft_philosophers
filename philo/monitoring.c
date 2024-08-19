/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:14:53 by anarama           #+#    #+#             */
/*   Updated: 2024/08/19 17:53:04 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_philo *philo)
{
	if (save_get_value(&philo->data->stop_mutex,
			&philo->data->stop_simulation) == 0)
	{
		save_print_action(philo, "died");
		save_set_value(&philo->data->stop_mutex,
			&philo->data->stop_simulation, 1);
	}
	//stop_simulation();
}

int	check_dead(t_philo *philo)
{
	if (save_get_value(&philo->data->stop_mutex,
			&philo->time_since_last_meal)
			>= philo->data->time_to_die)
	{
		philo_dead(philo);
		return (1);
	}
	return (0);
}

void	wait_philos(t_philo *philos)
{
	int	num_ready_philos;
	int	i;

	num_ready_philos = 0;
	i = 0;
	while (num_ready_philos != philos->data->num_of_philos)
	{
		if (!save_get_value(&philos->data->stop_mutex, &philos[i].is_ready))
		{
			i = 0;
			num_ready_philos = 0;
			continue ;
		}
		num_ready_philos++;
		i++;
	}
}

int	monitor(t_philo *philos)
{
	int	num_full_philos;
	int i;

	num_full_philos = 0;
	while(1)
	{
		i = 0;
		num_full_philos = 0;
		while (i < philos->data->num_of_philos)
		{
			if (check_dead(&philos[i]))
				return (1);
			if (philos->data->num_meals != -1
			&& save_get_value(&philos->data->stop_mutex, &philos[i].meals)
			>= philos->data->num_meals)
				num_full_philos++;
			i++;
		}
		if (num_full_philos == philos->data->num_of_philos)
			break ;
		//usleep(10);
	}
	return (0);
}

void	*monitor_philos(void *arg)
{
	t_philo *philos;

	philos = (t_philo *)arg;
	wait_philos(philos);
	save_set_value(&philos->data->stop_mutex,
		&philos->data->all_philos_ready, 1);
	if (monitor(philos))
		save_set_value(&philos->data->stop_mutex,
			&philos->data->stop_simulation, 1);
	return (NULL);
}
