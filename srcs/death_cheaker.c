/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_cheaker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:22:35 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/12 13:34:36 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_death(t_philo *p)
{
	int	death;
	pthread_mutex_lock(&p->death->death);
	death = p->death->is_death;
	pthread_mutex_unlock(&p->death->death);
	return (death);
}

int	is_dead(t_philo *p)
{
	if (check_death(p))
		return (1);
	if (time_diff(p->t_last_meal, timestamp()) >= p->data.tmp_die)
	{
		pthread_mutex_lock(&p->death->death);
		p->death->is_death++;
		if (p->death->is_death == 1)
			print_message(p, "Dead");
		pthread_mutex_unlock(&p->death->death);
		return (1);
	}
	return (0);		
}