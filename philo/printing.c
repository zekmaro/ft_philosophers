/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrejarama <andrejarama@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:36:34 by anarama           #+#    #+#             */
/*   Updated: 2024/08/02 11:19:22 by andrejarama      ###   ########.fr       */
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

void	print_action(int timestamp, int index, char *str)
{
	printf("%d %d %s\n", timestamp, index, str);
}
