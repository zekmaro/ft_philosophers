/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejarama <andrejarama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:39:10 by andrejarama       #+#    #+#             */
/*   Updated: 2024/07/07 00:41:36 by andrejarama      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	*print_philo_info()
{
	return (NULL);
}

void	check_input(int	*var, char *str)
{
	int		num;
	char	*temp;

	num = ft_atoi(str);
	temp = ft_itoa(num);
	if (!temp || ft_strncmp(temp, str, ft_strlen(str)) != 0)
	{
		free(temp);
		exit(EXIT_FAILURE);
	}
	free(temp);
	*var = num;
}

void	initialise_data(t_data *data, int argc, char **argv)
{
	check_input(&(data->num_philo), argv[1]);
	check_input(&(data->time_die), argv[2]);
	check_input(&(data->time_eat), argv[3]);
	check_input(&(data->time_sleep), argv[4]);
	if (argc == 6)
		check_input(&(data->times_to_eat), argv[5]);
}

int	main(int argc, char **argv)
{
	t_data	data;
	pthread_t	philo_1;

	if (argc > 6)
	{
		exit(EXIT_FAILURE);
	}
	ft_memset(&data, 0, sizeof(data));
	initialise_data(&data, argc, argv);
	pthread_create(&philo_1, NULL, print_philo_info, NULL);
	pthread_join(philo_1, NULL);
}