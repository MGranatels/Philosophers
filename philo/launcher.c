/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:31:53 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/30 12:25:57 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*rotine(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	long long var;
	
	philo = arg;
	info = philo->info;
	if (!(philo->id % 2))
		usleep(info->tmp_eat*1000);
	while (info->dead == 0)
	{
		check_philo_died(info, philo);
		print_selection(info, philo);
		usleep(info->tmp_sleep*1000);
		pthread_mutex_lock(&philo->mutex);
		print_action(info, philo, "is thinking");
		pthread_mutex_unlock(&philo->mutex);
	}
	return (NULL);
}

void	iniciate_philo(t_info *vars)
{
	int	i;

	i = vars->nbr_phil;
	while (--i >= 0)
		pthread_mutex_init(&vars->philo[i].mutex, NULL);
	while (++i < vars->nbr_phil)
	{
		vars->philo[i].info = vars;
		if (i == 0)
			vars->philo[i].info->first_timestamp = timestamp();
		vars->philo[i].info->first_timestamp = vars->philo[0].info->first_timestamp;
		vars->philo[i].id = i + 1;
		vars->philo[i].nbr_eat = 0;
		vars->philo[i].t_last_meal = 0;
		vars->philo[i].l_fork = i;
		vars->philo[i].r_fork = (i + 1) % vars->nbr_phil;
		vars->philo[i].info->dead = 0;
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
	return (1);
}
