/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:53:30 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/18 23:25:41 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_monitor(t_philo	*philo)
{
	t_philo *tmp;

	tmp = philo;
	while(1)
	{
		while(tmp)
		{
			pthread_mutex_lock(&tmp->data->eats);
			// pthread_mutex_lock(&tmp->data->print);
			if(ft_time() - tmp->last_meal > tmp->data->time_to_die)
			{
				tmp->data->finish = 1;
				ft_print(tmp,ft_time(),"died");
				return ;
			}
			pthread_mutex_unlock(&tmp->data->eats);
			// pthread_mutex_unlock(&tmp->data->print);
			tmp = tmp->next;
			if(tmp == philo)
				break;
		}
	}
}