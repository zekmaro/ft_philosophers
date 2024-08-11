/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:56:36 by anarama           #+#    #+#             */
/*   Updated: 2024/08/11 12:46:53 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_elapsed_time(struct timeval *start, struct timeval *end) 
{
    return (end->tv_sec - start->tv_sec) * 1000
		+ (end->tv_usec - start->tv_usec) / 1000;
}

void get_current_time(struct timeval *time) 
{
    gettimeofday(time, NULL);
}
