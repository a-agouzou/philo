/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagouzou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:46:40 by aagouzou          #+#    #+#             */
/*   Updated: 2023/04/19 00:43:00 by aagouzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_check(char *av)
{
	if (*av == '+')
		av++;
	while (*av)
	{
		if (!ft_isdigit(*av))
			return (0);
		av++;
	}
	return (1);
}

t_data	*ft_set_data(t_data *data, int ac, char **av)
{
	data->nbr_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	data->meals = 0;
	data->finish = 0;
	return (data);
}

t_data	*ft_init_data(int ac, char **av)
{
	t_data	*data;
	int		i;

	if (ac < 5 || ac > 6)
		return (NULL);
	i = 1;
	while (av[i])
	{
		if (!ft_check(av[i]))
			return (NULL);
		i++;
	}
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	return (ft_set_data(data, ac, av));
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = ft_init_data(argc, argv);
	if (!data)
		return (printf("Error: invalid argument\n"), 1);
	philo = create_philosphers(data, philo);
	if (!philo)
		return (printf("Error: faild to create philosophers\n"), 1);
	create_threads(philo, data);
}
