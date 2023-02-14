/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 00:24:39 by mgranate_ls       #+#    #+#             */
/*   Updated: 2023/02/07 00:23:38 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_isspace(char c)
{
	return ((c > 8 && c < 14) || c == 32);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	n;
	int	res;

	n = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * n);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((*str1) - (*str2));
}
