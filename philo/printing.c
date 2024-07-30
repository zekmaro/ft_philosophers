/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:36:34 by anarama           #+#    #+#             */
/*   Updated: 2024/07/30 20:37:24 by anarama          ###   ########.fr       */
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

void	print_action(int timestamp, int index, char *str)
{
	ft_printf("%d %d %s\n", timestamp, index, str);
}
