/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:50:03 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/14 12:18:01 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	is_valid_arg(char *av)
{
	while (*av && ft_isspace(*av))
		av++;
	if (*av == '-')
		return (exit_free (NULL, NULL, 1, \
		"Negative values are unacceptable."));
	if (*av == '+')
		av++;
	while (*av == '0')
		av++;
	while (*av)
	{
		if (!ft_isdigit(*av))
			return (exit_free(NULL, NULL, 1, \
			"Argument contains more than digits."));
		av++;
	}
	if (ft_strlen(av) >= 10 && ft_strcmp(av, "2147483647") > 0)
		return (exit_free(NULL, NULL, 1, \
		"Invalid surpassed max integer ability."));
	return (1);
}

int	check_arguments(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
		if (!is_valid_arg(av[i]))
			return (0);
	if (!ft_atoi(av[1]))
		return (exit_free(NULL, NULL, 1, "Argument can't be zero."));
	if (!ft_atoi(av[2]))
		return (exit_free(NULL, NULL, 1, "Argument can't be zero."));
	if (!ft_atoi(av[3]))
		return (exit_free(NULL, NULL, 1, "Argument can't be zero."));
	if (!ft_atoi(av[4]))
		return (exit_free(NULL, NULL, 1, "Argument can't be zero."));
	return (1);
}
