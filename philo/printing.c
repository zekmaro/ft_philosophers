/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:36:34 by anarama           #+#    #+#             */
/*   Updated: 2024/08/08 22:19:03 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_input_info(t_data *data)
{
	printf("number_of_philosophers %d\n", data->num_of_philos);
	printf("time_to_die %d\n", data->time_to_die);
	printf("time_to_eat %d\n", data->time_to_eat);
	printf("time_to_sleep %d\n", data->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat %d\n",
		data->num_meals);
}

void	save_print_action(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (philo->data->stop_simulation == 0)
	{
		printf("%d %d %s\n", philo->timestamp, philo->philo_index, str);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}
