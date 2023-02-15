/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 02:56:40 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/15 18:14:43 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	sleep_action(long long action, t_philo *p)
{
	long long	begin;
	long long	passed;

	begin = timestamp();
	passed = 0;
	while (!is_dead(p) && passed < action)
	{
		if (check_death(p))
			return (1);
		passed = time_diff(begin, timestamp());
	}
	return (passed >= action);
}

static void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (!(p->id % 2))
		usleep(10000);
	p->t_last_meal = timestamp();
	while (!is_dead(p))
	{
		if (eat(p))
			return (NULL);
		if ((p->nbr_time_ate != -1 && p->nbr_time_ate == p->data.nbr_times_eat) \
		|| is_dead(p))
			break ;
		print_message(p, "is sleeping");
		sleep_action(p->data.tmp_sleep, p);
		if (is_dead(p))
			return (NULL);
		print_message(p, "is thinking");
	}
	return (NULL);
}	

int	create_threads(t_philo **philo)
{
	static pthread_mutex_t	print;
	int						i;

	pthread_mutex_init(&print, NULL);
	i = -1;
	while (++i < (*philo)[0].data.nbr_phil)
	{
		(*philo)[i].print = &print;
		(*philo)[i].t_last_meal = 0;
	}
	i = -1;
	while (++i < (*philo)[0].data.nbr_phil)
		pthread_create(&(*philo)[i].philo, NULL, &routine, (*philo + i));
	i = -1;
	while (++i < (*philo)->data.nbr_phil)
		pthread_join((*philo)[i].philo, NULL);
	i = -1;
	while (++i < (*philo)->data.nbr_phil)
		pthread_mutex_destroy(&(*philo)[i].info[i].mutex_fork);
	return (1);
}
