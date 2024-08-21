/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_functionality.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:52:33 by anarama           #+#    #+#             */
/*   Updated: 2024/08/21 17:43:22 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	initialise_mutexes(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (!safe_handle_mutex(&forks[i], INIT))
			return (0);
		i++;
	}
	return (1);
}

int	create_threads(t_data *data, t_philo *philos,
			pthread_t *threads, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		philos[i].philo_index = i + 1;
		philos[i].data = data;
		philos[i].forks = forks;
		if (!safe_handle_thread(&threads[i], philo_lifecycle,
				&philos[i], CREATE))
			return (0);
		i++;
	}
	return (1);
}

int	join_threads(t_data *data, pthread_t *threads)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (!safe_handle_thread(&threads[i], NULL, NULL, JOIN))
			return (0);
		i++;
	}
	return (1);
}

int	destroy_mutexes(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (!safe_handle_mutex(&data->print_mutex, DESTROY)
		|| safe_handle_mutex(&data->stop_mutex, DESTROY))
		return (0);
	while (i < data->num_of_philos)
	{
		if (!safe_handle_mutex(&forks[i], DESTROY))
			return (0);
		i++;
	}
	return (1);
}
