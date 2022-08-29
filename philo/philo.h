/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:01:23 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/29 14:58:16 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	 PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	int				id;
	int				nbr_eat;
	long long		t_last_meal;
	int				l_fork;
	int				r_fork;
	pthread_mutex_t	mutex;
	pthread_t		thread;
	struct s_info	*info;
}					t_philo;

typedef struct s_info
{
	int				nbr_phil;
	int				tmp_die;
	int				tmp_eat;
	int				tmp_sleep;
	int				nbr_eat;
	int				dead;
	int				all_ate;
	long long		first_timestamp;
	pthread_mutex_t	main;
	pthread_mutex_t	forks[250];
	t_philo			*philo;
}					t_info;

//Resources
int			ft_atoi(const char *str);
int			ft_strlen(const char *s);
int			ft_strcmp(char *str1, char *str2);
int			ft_isdigit(int c);
long long	timestamp(void);

//Argumemnt Checks
int			check_arguments(char **arg, t_info *vars);

//Thread Creation and Manipulation
int			create_threads(t_info *vars);
void		*rotine(void *arg);
void		accounting_time(int	act, t_info *info);


//Clean Programm
void		exit_program(t_info *vars);
int			check_philo_died(t_info *info, t_philo *philo);
int			check_dead(t_info *info);

//Print Actions
int   	print_action(t_info *info, t_philo *philo, char *string);
int		print_selection (t_info *info, t_philo *philo);

#endif