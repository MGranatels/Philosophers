/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:22:31 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/14 12:42:58 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_data	init_data(int ac, char **av)
{
	t_data	data;

	data.nbr_phil = ft_atoi(av[1]);
	data.tmp_die = ft_atoi(av[2]);
	data.tmp_eat = ft_atoi(av[3]);
	data.tmp_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data.nbr_times_eat = ft_atoi(av[5]);
	else
		data.nbr_times_eat = -1;
	return (data);
}

t_info	*init_info(t_data *data)
{
	t_info	*info;
	int		i;

	info = malloc(sizeof(t_info) * data->nbr_phil);
	if (!info)
		return (NULL);
	i = -1;
	while (++i < data->nbr_phil)
	{
		info[i].have_fork = 1;
		pthread_mutex_init(&info[i].mutex_fork, NULL);
	}
	return (info);
}

t_death	*init_death(void)
{
	static t_death	death;

	pthread_mutex_init(&death.death, NULL);
	return (&death);
}

t_philo	*init_philo(t_data *data, t_info **info, t_death *death)
{
	t_philo	*philo;
	int		i;

	philo = malloc(sizeof(t_philo) * data->nbr_phil);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < data->nbr_phil)
	{
		philo[i].data = *data;
		philo[i].id = i + 1;
		philo[i].info = *info;
		philo[i].death = death;
		philo[i].nbr_time_ate = 0;
		philo[i].time = timestamp();
	}
	return (philo);
}
