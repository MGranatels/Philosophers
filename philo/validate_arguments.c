/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 14:31:58 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/22 15:13:38 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_arg(char *str)
{
	char			*tmp;
	unsigned int	len;

	if (!str || !str[0])
		return (0);
	tmp = str;
	if (*tmp == '-')
		return (0);
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	while (*tmp == '0')
		tmp++;
	len = ft_strlen(str) - (tmp - str);
	if (len > 10 || (ft_strlen(str) == 1 && (*str == '+' || *str == '-')))
		return (0);
	while (*tmp)
		if (!ft_isdigit(*tmp++))
			return (0);
	if (len == 10
		&& ft_strcmp(str + ft_strlen(str) - len, "2147483647") > 0)
		return (0);
	return (1);
}

int	check_arguments(char **arg, t_info *vars)
{
	int	i;
	int	j;

	i = 0;
	while (arg[++i])
	{
		if (!is_valid_arg(arg[i]))
			return (0);
	}
	if (!(vars->nbr_phil = ft_atoi(arg[1])))
		return (0);
	if (!(vars->tmp_die = ft_atoi(arg[2])))
		return (0);
	if (!(vars->tmp_eat = ft_atoi(arg[3])))
		return (0);
	if (!(vars->tmp_sleep = ft_atoi(arg[4])))
		return (0);
	if (arg[5])
		if (!(vars->nbr_eat = ft_atoi(arg[5])))
			return (0);
	return (1);
}

void	exit_program(t_info *vars)
{
	if (vars->philo)
		free(vars->philo);
}
