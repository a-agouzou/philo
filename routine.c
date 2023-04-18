/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:53:34 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/18 23:17:48 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_print(philo,ft_time(),"has taken a fork");
	pthread_mutex_lock(&philo->next->fork);
	ft_print(philo,ft_time(),"has taken a fork");
	ft_print(philo,ft_time(),"is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->eats);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->data->eats);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	ft_sleeping(t_philo	*philo)
{
	ft_print(philo, ft_time(), "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void	ft_thinking(t_philo	*philo)
{
	ft_print(philo, ft_time(), "is thinking");
}

void	*routine(void	*param)
{
	t_philo	*philo;

	philo = (t_philo	*)param;
	if(!(philo->id % 2))
		usleep(philo->data->time_to_eat * 1000);
	while(!(philo->data->finish))
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return NULL;
}