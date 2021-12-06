/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:45:08 by semin             #+#    #+#             */
/*   Updated: 2021/12/06 22:56:35 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <signal.h>

typedef struct s_philo
{
	int				num;
	useconds_t		last_ate;
	int				eating;
	pthread_t		check;
	int				ate;
	pid_t			pid;
	sem_t			*forks;
	sem_t			*print;
}	t_philo;

typedef struct s_params
{
	t_philo			*philo;
	useconds_t		start;
	int				philo_num;
	int				cur_num;
	useconds_t		die;
	useconds_t		eat;
	useconds_t		sleep;
	int				time_to_eat;
	int				dead;
}	t_params;

void		fork_init(t_params *params);
t_params	*param_init(int ac, char **av);

void		routine(t_params *params, t_philo *philo);

useconds_t	get_time(void);
float		time_gap(t_params *params);
void		my_usleep(useconds_t wait);

void		ft_error(t_params *params);
int			ft_free(t_params **params);
int			ft_atoi(char *s, t_params *params);

void		destroy_mutex(t_params *params);
void		kill_philo(t_params *params, t_philo *philo);

#endif
