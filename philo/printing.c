/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:36:34 by anarama           #+#    #+#             */
/*   Updated: 2024/08/19 16:35:32 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_input_info(t_data *data)
{
	ft_printf("number_of_philosophers %d\n", data->num_of_philos);
	ft_printf("time_to_die %d\n", data->time_to_die);
	ft_printf("time_to_eat %d\n", data->time_to_eat);
	ft_printf("time_to_sleep %d\n", data->time_to_sleep);
	ft_printf("number_of_times_each_philosopher_must_eat %d\n",
		data->num_meals);
}

void	save_print_action(t_philo *philo, const char *str)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (save_get_value(&philo->data->stop_mutex,
			&philo->data->stop_simulation) == 0)
	{
		get_current_time(&philo->time1);
		printf("%ld %d %s\n", get_elapsed_time(&philo->simulation_start,
			&philo->time1), philo->philo_index, str);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}
