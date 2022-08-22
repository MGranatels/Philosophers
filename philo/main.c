/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:02:46 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/21 21:35:58 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *first_thread(void *arg)
{
	int count;
	int	*arg2 = (int*)arg;
	count = 0;
	while (count < 10)
	{
		printf("count = %d\n", count);
		count++;
		sleep(1);
	}
	if (count == 10)
		*arg2 = count;
	return (arg2);
}

int main(int ac, char **av)
{
	static	t_info  vars;
	long long	nb;
	long long	nb2;
	int	maxnb = 283938484;
	if(ac == 5 || ac == 6)
	{
		if (!check_arguments(av, &vars))
			return (0);
		create_threads(&vars);
		free(vars.philo);
	}

	return (0);
}