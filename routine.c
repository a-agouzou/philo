/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:53:34 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 00:36:08 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_print(philo, ft_time(), "has taken a fork");
	pthread_mutex_lock(&philo->next->fork);
	ft_print(philo, ft_time(), "has taken a fork");
	ft_print(philo, ft_time(), "is eating");
	ft_usleep(ft_time(),philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->eats);
	philo->last_meal = ft_time();
	philo->meal += 1;
	if (philo->meal == philo->data->must_eat)
		philo->data->meals += 1;
	pthread_mutex_unlock(&philo->data->eats);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	ft_sleeping(t_philo *philo)
{
	ft_print(philo, ft_time(), "is sleeping");
	ft_usleep(ft_time(),philo->data->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	ft_print(philo, ft_time(), "is thinking");
}

void	*routine(void *param)
{
	int is_finish;
	t_philo *philo;

	philo = (t_philo *)param;
	if (!(philo->id % 2))
		usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->monitor);
	is_finish = philo->data->finish;
	pthread_mutex_unlock(&philo->data->monitor);
	while (!is_finish)
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
		pthread_mutex_lock(&philo->data->monitor);
		is_finish = philo->data->finish;
		pthread_mutex_unlock(&philo->data->monitor);
	}
	return (NULL);
}