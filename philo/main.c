/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:02:46 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/27 16:38:55 by mgranate_ls      ###   ########.fr       */
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
		i = vars.nbr_phil;
		while (--i >= 0)
			pthread_create(&(vars.philo[i].thread), NULL,
				&rotine, &vars.philo[i]);
		while (1)
		{
			pthread_mutex_lock(&vars.main);
			if (!check_philo_died(&vars, vars.philo))
			{
				exit_program(&vars);
				return (0);
			}
			pthread_mutex_unlock(&vars.main);
		}
	}
	return (0);
}
