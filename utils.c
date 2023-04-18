/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:53:05 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/18 22:14:40 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_print(t_philo *philo, long long time, char *s)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lld %d %s\n",(time - philo->data->start) , philo->id, s);
	pthread_mutex_unlock(&philo->data->print);
}

long long ft_time(void)
{
	struct timeval time;

	gettimeofday(&time,NULL);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(char *str)
{
	int	res;
	int	signe;
	int	i;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((res * signe));
}