/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:40:48 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/07 00:18:42 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	*info;
	t_data	data;
	t_death	*death;

	if (ac != 5 && ac != 6)
		return(exit_free(NULL, NULL, 1, "Wrong Number of Arguments"));
	if (!check_arguments(av, &data))
		return(0);
	info = init_info(&data);
	if (!info)
		return(exit_free(NULL, NULL, 1, "Allocation Failed for Info"));
	death = init_death();
	philo = init_philo(&data, &info, death);
	if (!philo)
		return(exit_free(NULL, NULL, 1, "Allocation Failed for Philo"));
	create_threads(&philo);
	exit_free(&info, &philo, 0, NULL);
}