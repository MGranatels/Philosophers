/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:12:00 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/14 11:48:10 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	putting_fork(t_philo *p, int fork)
{
	pthread_mutex_lock(&p->info[fork].mutex_fork);
	p->info[fork].have_fork = 1;
	pthread_mutex_unlock(&p->info[fork].mutex_fork);
}

static void	taking_fork(t_philo *p, int fork)
{
	while (!is_dead(p))
	{
		pthread_mutex_lock(&p->info[fork].mutex_fork);
		if (p->info[fork].have_fork)
		{
			p->info[fork].have_fork = 0;
			pthread_mutex_unlock(&p->info[fork].mutex_fork);
			break ;
		}
		else
			pthread_mutex_unlock(&p->info[fork].mutex_fork);
	}
}

int	eat(t_philo *p)
{
	int	first;
	int	second;

	first = ((p->id == 1) * (p->data.nbr_phil - 1)) + \
	((p->id != 1) * (p->id - 1));
	second = (p->id - 1 - (p->id != 1));
	taking_fork(p, first);
	if (check_death(p))
		return (1);
	print_message(p, "has taken a fork");
	taking_fork(p, second);
	if (check_death(p))
		return (1);
	print_two_message(p);
	p->nbr_time_ate++;
	p->t_last_meal = timestamp();
	sleep_action(p->data.tmp_eat, p);
	putting_fork(p, first);
	putting_fork(p, second);
	return (0);
}
