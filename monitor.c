/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:53:30 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 00:48:50 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_monitor(t_philo *philo)
{
	t_philo *tmp;

	tmp = philo;
	while (1)
	{
		while (tmp)
		{
			pthread_mutex_lock(&tmp->data->eats);
			if (ft_time() - tmp->last_meal > tmp->data->time_to_die)
			{
				pthread_mutex_lock(&tmp->data->monitor);
				tmp->data->finish = 1;
				pthread_mutex_unlock(&tmp->data->monitor);
				ft_print(tmp, ft_time(), "died");
				return ;
			}
			pthread_mutex_lock(&tmp->data->print);
			if (tmp->data->meals == tmp->data->nbr_of_philo)
			{
				pthread_mutex_lock(&tmp->data->monitor);
				tmp->data->finish = 1;
				pthread_mutex_unlock(&tmp->data->monitor);
				return ;
			}
			pthread_mutex_unlock(&tmp->data->print);
			pthread_mutex_unlock(&tmp->data->eats);
			tmp = tmp->next;
			if (tmp == philo)
				break ;
		}
	}
}