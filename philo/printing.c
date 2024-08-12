/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:36:34 by anarama           #+#    #+#             */
/*   Updated: 2024/08/12 15:51:11 by anarama          ###   ########.fr       */
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

void	save_print_action(t_philo *philo, const char *str)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (save_get_value(&philo->data->stop_mutex,
				&philo->data->stop_simulation) == 0)
	{
		get_current_time(&philo->time1);
		printf("%d %d %s\n", get_elapsed_time(&philo->simulation_start, &philo->time1), philo->philo_index, str);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}
