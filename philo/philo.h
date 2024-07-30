/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:45:32 by andrejarama       #+#    #+#             */
/*   Updated: 2024/07/30 14:03:53 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stddef.h>
# include <stdlib.h>
# include <signal.h>
# include <pthread.h>
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_to_eat;
	int	philo_index;
	pthread_mutex_t lock;
}	t_data;

typedef struct s_philo
{
	int	philo_index;
	t_data *data;	
}	t_philo;

void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_memset(void *str, int c, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlen(const char *str);

#endif // PHILO_H