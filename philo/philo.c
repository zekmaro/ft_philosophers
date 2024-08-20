/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:39:10 by andrejarama       #+#    #+#             */
/*   Updated: 2024/08/20 17:34:01 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(pthread_t *threads, t_philo *philos,
				t_data *data, pthread_mutex_t *forks)
{
	pthread_t monitor_thread;

	initialise_mutexes(data, forks);
	create_threads(data, philos, threads, forks);
	safe_handle_thread(&monitor_thread, monitor_philos, philos, CREATE);
	join_threads(data, threads);
	safe_handle_thread(&monitor_thread, NULL, NULL, JOIN);
	destroy_mutexes(data, forks);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	*forks = NULL;
	pthread_t		*threads = NULL;
	t_philo			*philos = NULL;
	t_data			data;

	if (argc < 5 || argc > 6)
	{
		exit(EXIT_FAILURE);
	}
	ft_memset(&data, 0, sizeof(data));
	initialise_data(&data, argc, argv);
	initialise_memory(&threads, &philos, &data, &forks);
	start_simulation(threads, philos, &data, forks);
	free(philos);
	free(threads);
	free(forks);
}
