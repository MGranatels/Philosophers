/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:50:03 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/12 14:09:00 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	is_valid_arg(char *av)
{
	while (*av && ft_isspace(*av))
		av++;
	if (*av == '-')
		return(exit_free(NULL, NULL, 1, "Negative values are unacceptable."));
	if (*av == '+')
		av++;
	while (*av == '0')
		av++;
	while (*av)
	{
		if (!ft_isdigit(*av))
			return (exit_free(NULL, NULL, 1, "Argument contains more than digits."));
		av++;
	}
	if (ft_strlen(av) >= 10 && ft_strcmp(av, "2147483647") > 0)
		return (exit_free(NULL, NULL, 1, "Invalid surpassed max integer ability."));
	return (1);
}

int	check_arguments(char **av, t_data *data)
{
	int	i;
	
	i = 0;
	while (av[++i])
		if (!is_valid_arg(av[i]))
			return (0);
	if (!(data->nbr_phil = ft_atoi(av[1])))
		return (exit_free(NULL, NULL, 1, "Argument can't be zero."));
	if (!(data->tmp_die = ft_atoi(av[2])))
		return (exit_free(NULL, NULL, 1, "Argument can't be zero."));
	if(!(data->tmp_eat = ft_atoi(av[3])))
		return (exit_free(NULL, NULL, 1, "Argument can't be zero."));
	if(!(data->tmp_sleep = ft_atoi(av[4])))
		return (exit_free(NULL, NULL, 1, "Argument can't be zero."));
	if (av[5])
	{
		if(!(data->nbr_times_eat = ft_atoi(av[5])))
			return (exit_free(NULL, NULL, 1, "Argument can't be zero."));
	}
	else
		data->nbr_times_eat = -1;
	return (1);
}