/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:31:53 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/22 15:23:06 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*rotine(void *arg) //sempre que entra aqui, estas dentro da thread
{
	t_philo	*philo;
	t_info	*info;

	philo = arg;
	info = philo->info;
	/* if (philo->id % 2)
		usleep(15000);  nao vais precisar porque quando as mutex trancarem, ele ja automaticamente vai fazer o que tu queres*/
	info->nbr_eat = 5;
	printf("Number Phill == %d\n", info->nbr_phil);
	return (NULL);
}

void	iniciate_philo(t_info *vars)s
	{
		vars->philo[i].id = i + 1;
		vars->philo[i].nbr_eat = 0;
		vars->philo[i].t_last_meal = 0;
		vars->philo[i].l_fork = i;
		vars->philo[i].r_fork = (i + 1) % vars->nbr_phil;
	}
	vars->philo[0].l_fork = vars->nbr_phil;
	vars->philo[vars->nbr_phil - 1].r_fork = vars->nbr_phil;
}

int	create_lists(t_info *vars)
{
	vars->philo = malloc((vars->nbr_phil) * sizeof(t_philo));
	if (!vars->philo)
		return (0);
	return (1);
}

int	create_threads(t_info *vars)
{
	int	i;

	i = vars->nbr_phil;
	vars->first_timestamp = timestamp();
	if (!create_lists(vars))
		return (0);
	iniciate_philo(vars);
	while (--i >= 0)
	{
		pthread_create(&(vars->philo[i].thread), NULL,
			&rotine, &vars->philo[i]);
		vars->philo[i].t_last_meal = timestamp();
	}
	pthread_join(&vars->philo[i].thread);
	exit_program(vars);
	return (1);
}
