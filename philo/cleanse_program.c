/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanse_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:58:53 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/25 12:34:47 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_died(t_info info)
{
	
	return (1);
}

void	exit_program(t_info *vars)
{
    int i;

    i = vars->nbr_phil;
	while (--i >= 0)
		pthread_join(vars->philo[i].thread, NULL);
    i = vars->nbr_phil;
	while (--i >= 0)
		pthread_mutex_destroy(&vars->philo[i].mutex);
	if (vars->philo)
		free(vars->philo);
}
