/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anarama <anarama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:45:32 by andrejarama       #+#    #+#             */
/*   Updated: 2024/08/09 12:36:08 by anarama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <stddef.h>
# include <stdlib.h>
# include <signal.h>
# include <pthread.h>
# include <errno.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"


typedef enum s_mode_mutex
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
}	t_mode_mutex;

typedef enum s_mode_thread
{
	CREATE,
	JOIN,
	DETACH
}	t_mode_thread;

typedef struct s_data
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	int				stop_simulation;
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
	struct timeval	time0;
	struct timeval	time1;
	t_data			*data;
	int				timestamp;
	int				philo_index;
	int				is_dead;
	int				has_left_fork;
	int				has_right_fork;
	int				meals;
	int				time_since_last_meal;
}	t_philo;

void	*ft_calloc(size_t num, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
void	*ft_memset(void *str, int c, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlen(const char *str);
void	*philo_lifecycle(void *arg);

/* Forks */
void	get_two_forks(t_philo *philo, int left_fork, int right_fork);
void	pick_up_left_fork(t_philo *philo, int left_fork);
void	pick_up_right_fork(t_philo *philo, int right_fork);
void	put_down_left_fork(t_philo *philo, int left_fork);
void	put_down_right_fork(t_philo *philo, int right_fork);

/* Philo_actions */
void	philo_dead(t_philo *philo);
void	check_dead(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);

/* Printing */
void	print_input_info(t_data *data);
void	save_print_action(t_philo *philo, char *str);

void	stop_simulation();
void 	get_current_time(struct timeval *time);
long	get_elapsed_time(struct timeval *start, struct timeval *end);

/* Protections */
void	print_error(char *str);
void	safe_handle_mutex(pthread_mutex_t *mutex, t_mode_mutex mode);
void	safe_handle_thread(pthread_t *thread, void *(*start_routine) (void *),
				void *arg, t_mode_thread mode);

/* Initialisations */
void	initialise_mutexes(t_data *data, pthread_mutex_t *forks);
void	create_threads(t_data *data, t_philo *philos,
			pthread_t *threads, pthread_mutex_t *forks);
void	join_threads(t_data *data, pthread_t *threads);
void	destroy_mutexes(t_data *data, pthread_mutex_t *forks);

/* Initialisation and parsing */
void	check_input(int	*var, char *str);
void	initialise_memory(pthread_t **threads, t_philo **philos,
				t_data *data, pthread_mutex_t **forks);
void	initialise_data(t_data *data, int argc, char **argv);

/* Save get and set */
void	save_set_value(pthread_mutex_t *mutex, int *value, int new_value);
int		save_get_value(pthread_mutex_t *mutex, int *value);

#endif // PHILO_H