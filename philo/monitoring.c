/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:14:53 by anarama           #+#    #+#             */
/*   Updated: 2024/08/10 18:43:48 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_philos(void *arg)
{
	t_philo *philos;
	int		num_ready_philos;
	int i;

	philos = (t_philo *)arg;
	i = 0;
	num_ready_philos = 0;
	while (num_ready_philos != philos->data->num_of_philos)
	{
		if (!save_get_value(&philos->data->stop_mutex, &philos[i].is_ready))
		{
			i = 0;
			num_ready_philos = 0;
			continue ;
		}
		num_ready_philos++;
		i++;
	}
	save_set_value(&philos->data->stop_mutex, &philos->data->all_philos_ready, 1);
	i = 0;
	while(1)
	{
		while (i < philos->data->num_of_philos)
		{
			check_dead(&philos[i]);
			i++;	
		}
		i = 0;
		usleep(10 * 1000);
	}
	return (NULL);
}
