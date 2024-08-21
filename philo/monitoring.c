/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:14:53 by anarama           #+#    #+#             */
/*   Updated: 2024/08/21 17:46:47 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_philo *philo)
{
	if (safe_get_value(&philo->data->stop_mutex,
			&philo->data->stop_simulation) == 0)
	{
		safe_print_action(philo, "died");
		safe_set_value(&philo->data->stop_mutex,
			&philo->data->stop_simulation, 1);
	}
}

int	check_dead(t_philo *philo)
{
	if (safe_get_value(&philo->data->stop_mutex,
			&philo->time_since_last_meal)
		>= philo->data->time_to_die)
	{
		philo_dead(philo);
		return (1);
	}
	return (0);
}

int	monitor(t_philo *philos)
{
	int	num_full_philos;
	int	i;

	num_full_philos = 0;
	while (1)
	{
		i = 0;
		num_full_philos = 0;
		while (i < philos->data->num_of_philos)
		{
			if (check_dead(&philos[i]))
				return (1);
			if (philos->data->num_meals != -1
				&& safe_get_value(&philos->data->stop_mutex,
					&philos[i].meals)
				>= philos->data->num_meals)
				num_full_philos++;
			i++;
		}
		if (num_full_philos == philos->data->num_of_philos)
			return (1);
		usleep(1);
	}
	return (0);
}

void	*monitor_philos(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	safe_set_value(&philos->data->stop_mutex,
		&philos->data->all_philos_ready, 1);
	if (monitor(philos))
		safe_set_value(&philos->data->stop_mutex,
			&philos->data->stop_simulation, 1);
	return (NULL);
}
