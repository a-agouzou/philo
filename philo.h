/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:47:16 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 00:43:44 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	long long		start;
	int				nbr_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	int				time_to_die;
	int				must_eat;
	int				finish;
	pthread_mutex_t	print;
	pthread_mutex_t	eats;
	pthread_mutex_t	monitor;
}					t_data;

typedef struct s_philo
{
	int				id;
	long long		last_meal;
	pthread_t		thread;
	int				meal;
	pthread_mutex_t	fork;
	struct s_philo	*next;
	struct s_data	*data;
}					t_philo;

int					ft_atoi(char *str);
t_philo				*create_philosphers(t_data *data, t_philo *philo);
t_philo				*ft_create_ph(int id, t_data *data);
void				ft_monitor(t_philo *philo);
t_philo				*ft_addfront(t_philo *philo, t_philo *new);
void				*routine(void *param);
void				ft_usleep(long long time, int time_to_usleep);
long long			ft_time(void);
void				create_threads(t_philo *philo, t_data *data);
void				ft_print(t_philo *philo, long long time, char *s);
#endif