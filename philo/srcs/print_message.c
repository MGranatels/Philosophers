/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:57:30 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/12 14:00:24 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_two_message(t_philo *p)
{
	pthread_mutex_lock(p->print);
	printf("%llu %d %s\n", \
	time_diff(p->time, timestamp()), p->id, "has taken a fork");
	printf("%llu %d %s\n", \
	time_diff(p->time, timestamp()), p->id, "is eating");
	pthread_mutex_unlock(p->print);
	p->t_last_meal = timestamp();
}

void	print_message(t_philo *p, char *str)
{
	pthread_mutex_lock(p->print);
	printf("%llu %d %s\n", \
	time_diff(p->time, timestamp()), p->id, str);
	pthread_mutex_unlock(p->print);
}
