/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:39:10 by andrejarama       #+#    #+#             */
/*   Updated: 2024/07/30 15:35:42 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "stdio.h"

void	print_input_info(t_data *data)
{
	ft_printf("number_of_philosophers %d\n", data->num_of_philo);
	ft_printf("time_to_die %d\n", data->time_to_die);
	ft_printf("time_to_eat %d\n", data->time_to_eat);
	ft_printf("time_to_sleep %d\n", data->time_to_sleep);
	ft_printf("number_of_times_each_philosopher_must_eat %d\n", data->num_of_times_to_eat);
}

void	*print_philo(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	printf("%d has taken a fork\n", philos->philo_index);
	printf("%d is eating\n", philos->philo_index);
	printf("%d is sleeping\n", philos->philo_index);
	printf("%d is thinking\n", philos->philo_index);
	printf("%d died\n", philos->philo_index);
	return (NULL);
}

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
	check_input(&(data->num_of_philo), argv[1]);
	check_input(&(data->time_to_die), argv[2]);
	check_input(&(data->time_to_eat), argv[3]);
	check_input(&(data->time_to_sleep), argv[4]);
	if (argc == 6)
		check_input(&(data->num_of_times_to_eat), argv[5]);
	else
		data->num_of_times_to_eat = -1;
}

void	start_simulation(pthread_t *threads, t_philo *philos, t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_of_philo)
	{
		philos[i].philo_index = i + 1;
		philos[i].data = data;
		pthread_create(&threads[i], NULL, print_philo, &philos[i]);
		i++;
	}
	i = 0;
	while (i < data->num_of_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	initialise_threads_and_philos(pthread_t	**threads, t_philo **philos, t_data *data)
{
	*threads = malloc(data->num_of_philo * sizeof(pthread_t));
	*philos = malloc(data->num_of_philo * sizeof(t_philo));
	if (!*threads || !*philos)
	{
		ft_printf("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	ft_memset(*threads, 0, data->num_of_philo * sizeof(pthread_t));
	ft_memset(*philos, 0, data->num_of_philo * sizeof(t_philo));
}

int	main(int argc, char **argv)
{
	pthread_t	*threads = NULL;
	t_philo		*philos = NULL;
	t_data		data;
	int			i;

	if (argc < 4 || argc > 6)
	{
		exit(EXIT_FAILURE);
	}
	i = 0;
	ft_memset(&data, 0, sizeof(data));
	initialise_data(&data, argc, argv);
	initialise_threads_and_philos(&threads, &philos, &data);
	print_input_info(&data);
	start_simulation(threads, philos, &data);
	free(philos);
	free(threads);
}
