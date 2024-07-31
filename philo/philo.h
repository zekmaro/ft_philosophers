/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:45:32 by andrejarama       #+#    #+#             */
/*   Updated: 2024/07/31 19:59:40 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stddef.h>
# include <stdlib.h>
# include <signal.h>
# include <pthread.h>
# include <sys/time.h>
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
	pthread_mutex_t	print_mutex;
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	int				philo_index;
}	t_data;

typedef struct s_philo
{
	pthread_mutex_t	*forks;
	struct timeval	current_time;
	struct timeval time0;
	struct timeval time1;
	t_data			*data;
	int				timestamp;
	int				philo_index;
	int				is_dead;
	int				has_left_fork;
	int				has_right_fork;
	int				meals;
	int				have_eaten;
	int				have_slept;
	int				time_since_last_meal;
}	t_philo;

void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_memset(void *str, int c, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlen(const char *str);

/*forks.c*/
void	get_two_forks(t_philo *philo, int left_fork, int right_fork);
void	pick_up_left_fork(t_philo *philo, int left_fork);
void	pick_up_right_fork(t_philo *philo, int right_fork);
void	put_down_left_fork(t_philo *philo, int left_fork);
void	put_down_right_fork(t_philo *philo, int right_fork);

/*philo_actions.c*/
void	philo_dead(t_philo *philo);
void	check_dead(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);

/*printing.c*/
void	print_input_info(t_data *data);
void	print_action(int timestamp, int index, char *str);

void	stop_simulation();
void 	get_current_time(struct timeval *time);
long	get_elapsed_time(struct timeval *start, struct timeval *end);
#endif // PHILO_H