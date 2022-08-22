/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:02:46 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/22 14:18:44 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	static t_info	vars;

	if (ac == 5 || ac == 6)
	{
		if (!check_arguments(av, &vars))
			return (0);
		create_threads(&vars);
	}
	return (0);
}
