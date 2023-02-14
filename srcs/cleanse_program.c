/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanse_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:20:02 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/07 00:18:33 by mgranate_ls      ###   ########.fr       */
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
		if (&(*philo)->death->death)
			pthread_mutex_destroy(&(*philo)->death->death);
		if ((*philo)->print)
			pthread_mutex_destroy((*philo)->print);
		free(*philo);
	}
	return (0);
}