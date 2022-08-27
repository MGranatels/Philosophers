/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:44:35 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/27 03:46:08 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int    print_action(t_info *info, t_philo *philo, char *string)
{
    long long   time;
    int         dif;
    int         j;

    j = -1;
    time = timestamp();
    pthread_mutex_lock(&info->print_ex);
    dif = time - info->first_timestamp;
    while (++j < info->nbr_phil)
		if (info->philo[j].info->dead == 1)
			return (0);
    printf("%d %d %s\n", dif, philo->id, string);
    pthread_mutex_unlock(&info->print_ex);
    return (1);
}