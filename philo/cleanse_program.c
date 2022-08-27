/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanse_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:58:53 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/27 16:35:28 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_died(t_info *info, t_philo *philo)
{
	int			i;
	int 		dif;
	long long 	time;
	
    time = timestamp();
    pthread_mutex_lock(&philo->mutex);
	dif = time - info->first_timestamp;
	if (!check_dead(info))
		return (0);
	i = time - philo->t_last_meal;
	if (i > info->tmp_die)
	{
		info->dead = 1;
		printf("%d %d dead\n", dif, philo->id);
		return (0);
	}
    pthread_mutex_unlock(&philo->mutex);
	return (1);
}

int	check_dead(t_info *info)
{
	int	j;

	j = -1;
	while (++j < info->nbr_phil)
		if (info->philo[j].info->dead == 1)
			return (0);
	return (1);
}

void	exit_program(t_info *vars)
{
    int i;

    //i = vars->nbr_phil;
	while (--i >= 0)
		pthread_detach(vars->philo[i].thread);
    i = vars->nbr_phil;
	while (--i >= 0)
		pthread_mutex_destroy(&vars->philo[i].mutex);
	if (vars->philo)
		free(vars->philo);
}
