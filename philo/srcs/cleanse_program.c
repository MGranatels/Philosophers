/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanse_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:20:02 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/14 12:43:58 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	exit_free(t_info **info, t_philo **philo, int status, char *error)
{
	int	i;

	if (status)
		printf("%s\n", error);
	i = -1;
	if (info && *info)
	{
		while (i++ < (*philo)[0].data.nbr_phil)
			pthread_mutex_destroy(&(*info)[i].mutex_fork);
		free(*info);
	}
	if (philo && *philo)
	{
		pthread_mutex_destroy(&(*philo)->death->death);
		pthread_mutex_destroy((*philo)->print);
		free(*philo);
	}
	return (0);
}
