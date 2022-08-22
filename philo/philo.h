/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgranate_ls <mgranate_ls@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:01:23 by mgranate_ls       #+#    #+#             */
/*   Updated: 2022/08/22 11:57:13 by mgranate_ls      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_H
# define _PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>

typedef enum		e_state
{
	EATING,
	SLEEPING,
	THINKING,
	RUNNING,
	FINISHED
}					t_state;

typedef	struct		s_philo
{
	int				id;
	int				nbr_eat;
	long long		t_last_meal;
	int				l_fork;
	int				r_fork;
	pthread_mutex_t	eat_ex;
	pthread_t		thread;
	struct s_info	*info;
}					t_philo;

typedef struct		s_info
{
	int				nbr_phil;
	int				tmp_die;
	int				tmp_eat;
	int				tmp_sleep;
	int				nbr_eat;
	int				dead;
	int				all_ate;
	long long		first_timestamp;
	pthread_mutex_t	print_ex;
	pthread_mutex_t	start_ex;
	t_philo			*philo;
	t_state			state;
}					t_info;


//Resources
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		ft_strcmp(char *str1, char *str2);
int		ft_isdigit(int c);
long long	timestamp(void);

//Argumemnt Checks
int		check_arguments(char **arg, t_info *vars);

//Thread Creation and Manipulation
int		create_threads(t_info *vars);
#endif