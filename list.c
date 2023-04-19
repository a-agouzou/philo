/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:53:25 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 00:42:12 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

t_philo	*ft_create_ph(int id, t_data *data)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo));
	if (!new)
		return (0);
	new->id = id + 1;
	new->data = data;
	new->next = NULL;
	return (new);
}

t_philo	*get_last(t_philo *philo)
{
	t_philo	*cursor;

	cursor = philo;
	while (cursor->next != philo)
		cursor = cursor->next;
	return (cursor);
}

t_philo	*ft_addfront(t_philo *philo, t_philo *new)
{
	t_philo	*last;

	if (!philo)
	{
		new->next = new;
		return (new);
	}
	last = get_last(philo);
	last->next = new;
	new->next = philo;
	return (philo);
}
