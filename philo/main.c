/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:02:46 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/27 02:26:07 by mgranate_ls      ###   ########.fr       */
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
		exit_program(&vars);
		//check_philo_died(&vars);
	}
	return (0);
}
