/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_and_parsing.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:03:36 by anarama           #+#    #+#             */
/*   Updated: 2024/08/13 17:39:56 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	save_calloc(void **ptr, int num, int size)
{
	*ptr = ft_calloc(num, size);
	if (!*ptr)
	{
		print_error("Error allocating memory");
		exit(EXIT_FAILURE);
	}
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

void	initialise_memory(pthread_t **threads, t_philo **philos,
				t_data *data, pthread_mutex_t **forks)
{
	save_calloc((void **)threads, data->num_of_philos, sizeof(pthread_t));
	// lst_memory((void *)threads, free, ADD);
	save_calloc((void **)philos, data->num_of_philos, sizeof(t_philo));
	// lst_memory((void *)philos, free, ADD);
	save_calloc((void **)forks, data->num_of_philos, sizeof(pthread_mutex_t));
	// lst_memory((void *)forks, free, ADD);
	safe_handle_mutex(&data->print_mutex, INIT);
	safe_handle_mutex(&data->stop_mutex, INIT);
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
