/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:44:35 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/27 16:27:53 by mgranate_ls      ###   ########.fr       */
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
    dif = time - info->first_timestamp;
    //pthread_mutex_lock(&philo->mutex);
    if(!check_dead(info))
        return (0);
    printf("%d %d %s\n", dif, philo->id, string);
    //pthread_mutex_unlock(&philo->mutex);
    return (1);
}