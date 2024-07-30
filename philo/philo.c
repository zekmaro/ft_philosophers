/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejarama <andrejarama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:39:10 by andrejarama       #+#    #+#             */
/*   Updated: 2024/07/29 21:09:52 by andrejarama      ###   ########.fr       */
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
	pthread_t tid;

	tid = pthread_self();
	printf("Philo with id: %lu\n", (unsigned long)tid);
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

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	*philos;
	int			i;

	if (argc < 5 || argc > 6)
	{
		exit(EXIT_FAILURE);
	}
	i = 0;
	ft_memset(&data, 0, sizeof(data));
	initialise_data(&data, argc, argv);
	print_input_info(&data);
	philos = malloc(data.num_of_philo * sizeof(pthread_t));
	if (!philos)
	{
		ft_printf("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	ft_memset(philos, 0, data.num_of_philo * sizeof(pthread_t));
	while (i < data.num_of_philo)
	{
		pthread_create(&philos[i], NULL, print_philo, &data);
		i++;
	}
	i = 0;
	while (i < data.num_of_philo)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	free(philos);
}
