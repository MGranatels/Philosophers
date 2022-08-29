/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:02:46 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/29 18:10:23 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	static t_info	vars;
	int		i;

	if (ac == 5 || ac == 6)
	{
		if (!check_arguments(av, &vars))
			return (0);
		create_threads(&vars);
		i = -1;
		while (++i < vars.nbr_phil)
			pthread_create(&(vars.philo[i].thread), NULL,
				&rotine, &vars.philo[i]);
		while (1)
		{
			pthread_mutex_lock(&vars.main);
			if (!check_philo_died(&vars, vars.philo))
				return (0);
			pthread_mutex_unlock(&vars.main);
		}
	}
	return (0);
}
