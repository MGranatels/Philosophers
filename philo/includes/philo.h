/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate <mgranate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:27:10 by mgranate          #+#    #+#             */
/*   Updated: 2023/02/14 12:42:11 by mgranate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct s_info	t_info;
typedef struct s_death	t_death;

struct s_death
{
	int				is_death;
	pthread_mutex_t	death;
};

struct s_data
{
	int	nbr_phil;
	int	tmp_die;
	int	tmp_eat;
	int	tmp_sleep;
	int	nbr_times_eat;
};

struct s_info
{
	int				have_fork;
	pthread_mutex_t	mutex_fork;
};

struct s_philo
{
	int				id;
	int				nbr_time_ate;
	long long		time;
	long long		t_last_meal;
	int				l_fork;
	int				r_fork;
	pthread_mutex_t	*print;
	pthread_t		philo;
	t_death			*death;
	t_info			*info;
	t_data			data;
};

//Iniciate Data Struct
t_info		*init_info(t_data *data);
t_death		*init_death(void);
t_philo		*init_philo(t_data *data, t_info **info, t_death *death);
t_data		init_data(int ac, char **av);

//Resources
int			ft_atoi(const char *str);
int			ft_strlen(const char *s);
int			ft_isspace(char c);
int			ft_strcmp(char *str1, char *str2);
int			ft_isdigit(int c);

// Time Line
long long	timestamp(void);
long long	time_diff(long long start, long long l_ac);

//Argumemnt Checks
int			check_arguments(char **av);
int			exit_free(t_info **info, t_philo **philo, int status, char *error);

//Thread Creation and Manipulation
int			create_threads(t_philo **philo);
int			is_dead(t_philo *p);
void		accounting_tim2e(int act, t_info *info);

//Actions
int			eat(t_philo *p);
int			sleep_action(long long action, t_philo *p);

//Death Checker
int			check_death(t_philo *p);
int			check_philo_died(t_info *info, t_philo *philo);

//Clean Programm
void		exit_program(t_info *vars);

//Print Actions
void		print_two_message(t_philo *p);
void		print_message(t_philo *p, char *str);

#endif