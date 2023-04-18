/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:04:29 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/18 23:24:32 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	detach_threads(t_philo	*philo)
{
	t_philo	*tmp;

	tmp = philo;
	while(tmp)
	{
		pthread_detach(tmp->thread);
		tmp = tmp->next;
		if(tmp == philo)
			break;
	}
}

void	create_threads(t_philo	*philo, t_data *data)
{
	t_philo *tmp;
	
	tmp = philo;
	pthread_mutex_init(&philo->data->print,NULL);
	pthread_mutex_init(&philo->data->eats,NULL);
	data->start = ft_time();
	while(tmp)
	{
		tmp->last_meal = data->start;
		pthread_create(&tmp->thread,NULL,routine,tmp);
		tmp = tmp->next;
		if(tmp == philo)
			break;
	}
	detach_threads(philo);
	ft_monitor(philo);
	// will be removed
	// while(tmp)
	// {
	// 	pthread_join(tmp->thread,NULL);
	// 	tmp = tmp->next;
	// 	if(tmp == philo)
	// 		break;
	// }
	// *************
}

t_philo	*create_philosphers(t_data *data, t_philo *philo)
{
	t_philo	*tmp;
	int	i;
	
	philo = NULL;
	i = -1;
	while(++i < data->nbr_of_philo)
		philo = ft_addfront(philo,ft_create_ph(i,data));
	tmp = philo;
	while(tmp)
	{
		pthread_mutex_init(&tmp->fork,NULL);
		tmp = tmp->next;
		if(tmp == philo)
			break;
	}
	return philo;
}