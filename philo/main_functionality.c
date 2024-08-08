/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:52:33 by anarama           #+#    #+#             */
/*   Updated: 2024/08/08 21:59:37 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialise_mutexes(t_data *data, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		safe_handle_mutex(&forks[i], INIT);
		i++;
	}
}

void	create_threads(t_data *data, t_philo *philos,
			pthread_t *threads, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		philos[i].philo_index = i + 1;
		philos[i].data = data;
		philos[i].forks = forks;
		safe_handle_thread(&threads[i], philo_lifecycle, &philos[i], CREATE);
		i++;
	}
}

void	join_threads(t_data *data, pthread_t *threads)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		safe_handle_thread(&threads[i], NULL, NULL, JOIN);
		i++;
	}
}

void	destroy_mutexes(t_data *data, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		safe_handle_mutex(&forks[i], DESTROY);
		i++;
	}
}