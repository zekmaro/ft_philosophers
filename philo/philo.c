/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:39:10 by andrejarama       #+#    #+#             */
/*   Updated: 2024/08/23 17:47:50 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(pthread_t *threads, t_philo *philos,
				t_data *data, pthread_mutex_t *forks)
{
	pthread_t	monitor_thread;

	if (!initialise_mutexes(data, forks)
		|| !create_threads(data, philos, threads, forks)
		|| !safe_handle_thread(&monitor_thread, monitor_philos, philos, CREATE)
		|| !join_threads(data, threads)
		|| !safe_handle_thread(&monitor_thread, NULL, NULL, JOIN))
	{
		destroy_mutexes(data, forks);
		return ;
	}
	destroy_mutexes(data, forks);
}

int	check_invalid_data(t_data data)
{
	return (data.num_of_philos == 0
		|| data.time_to_die == 0
		|| data.time_to_eat == 0
		|| data.time_to_sleep == 0
		|| data.num_meals == 0);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philo			*philos;
	t_data			data;

	if (argc < 5 || argc > 6)
		return (EXIT_FAILURE);
	forks = NULL;
	threads = NULL;
	philos = NULL;
	ft_memset(&data, 0, sizeof(data));
	initialise_data(&data, argc, argv);
	if (check_invalid_data(data))
		return (EXIT_FAILURE);
	if (initialise_memory(&threads, &philos, &data, &forks))
	{
		define_chuncks(&data);
		start_simulation(threads, philos, &data, forks);
	}
	free(philos);
	free(threads);
	free(forks);
	return (EXIT_SUCCESS);
}
