/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:39:10 by andrejarama       #+#    #+#             */
/*   Updated: 2024/08/04 00:06:32 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	check_input(int	*var, char *str)
{
	int		num;
	char	*temp;

	num = ft_atoi(str);
	temp = ft_itoa(num);
	if (num < 0 || !temp || ft_strncmp(temp, str, ft_strlen(str)) != 0)
	{
		free(temp);
		exit(EXIT_FAILURE);
	}
	free(temp);
	*var = num;
}

void	initialise_data(t_data *data, int argc, char **argv)
{
	check_input(&(data->num_of_philos), argv[1]);
	check_input(&(data->time_to_die), argv[2]);
	check_input(&(data->time_to_eat), argv[3]);
	check_input(&(data->time_to_sleep), argv[4]);
	if (argc == 6)
		check_input(&(data->num_meals), argv[5]);
	else
		data->num_meals = -1;
}

void	stop_simulation()
{
	exit(EXIT_FAILURE);
}

void	feed_starving_philo(t_philo	*philo, int right_fork, int left_fork)
{
	if (philo->time_since_last_meal > philo->data->time_to_die / 2)
	{
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
		philo_eat(philo);
		put_down_right_fork(philo, right_fork);
		put_down_left_fork(philo, left_fork);
		philo_sleep(philo);
		philo_think(philo);
	}
}

void	delay_full_philo(t_philo *philo)
{
	if (philo->time_since_last_meal <= philo->data->time_to_die / 2)
	{
		usleep(philo->data->time_to_sleep / 2 * 1000);
		philo->time_since_last_meal += philo->data->time_to_sleep / 2;
		philo->timestamp += philo->data->time_to_sleep / 2;
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
	get_current_time(&philo->time0);
	while (1)
	{
		get_two_forks(philo, left_fork, right_fork);
		philo_eat(philo);
		get_current_time(&philo->time0);
		put_down_right_fork(philo, right_fork);
		put_down_left_fork(philo, left_fork);
		philo_sleep(philo);
		check_dead(philo);
		feed_starving_philo(philo, right_fork, left_fork);
		delay_full_philo(philo);
		check_dead(philo);
		if (philo->data->num_meals != -1
		&& philo->meals >= philo->data->num_meals)
			break ;
	}
	return (NULL);
}

void	start_simulation(pthread_t *threads, t_philo *philos,
				t_data *data, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		philos[i].philo_index = i + 1;
		philos[i].data = data;
		philos[i].forks = forks;
		pthread_create(&threads[i], NULL, philo_lifecycle, &philos[i]);
		i++;
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	initialise(pthread_t	**threads, t_philo **philos,
								t_data *data, pthread_mutex_t **forks)
{
	*threads = malloc(data->num_of_philos * sizeof(pthread_t));
	*philos = malloc(data->num_of_philos * sizeof(t_philo));
	*forks = malloc(data->num_of_philos * sizeof(pthread_mutex_t));
	if (!*threads || !*philos || !*forks)
	{
		ft_printf("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	ft_memset(*threads, 0, data->num_of_philos * sizeof(pthread_t));
	ft_memset(*philos, 0, data->num_of_philos * sizeof(t_philo));
	ft_memset(*forks, 0, data->num_of_philos * sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->stop_mutex, NULL);
}

int	main(int argc, char **argv)
{
	pthread_t		*threads = NULL;
	t_philo			*philos = NULL;
	pthread_mutex_t	*forks = NULL;
	t_data			data;

	if (argc < 4 || argc > 6)
	{
		exit(EXIT_FAILURE);
	}
	ft_memset(&data, 0, sizeof(data));
	initialise_data(&data, argc, argv);
	initialise(&threads, &philos, &data, &forks);
	print_input_info(&data);
	start_simulation(threads, philos, &data, forks);
	free(philos);
	free(threads);
	free(forks);
}
