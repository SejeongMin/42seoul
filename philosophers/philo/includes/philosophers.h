/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:45:08 by semin             #+#    #+#             */
/*   Updated: 2021/11/29 19:34:59 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	pthread_t		pthread;
	int				num;
	struct timeval	last_ate;
	pthread_mutex_t	*f1;
	pthread_mutex_t	*f2;
	int				dead;
}	t_philo;

typedef struct	s_params
{
	t_philo			*philo;
	pthread_mutex_t *forks;
	pthread_mutex_t m;
	int				philo_num;
	int				cur_num;
	useconds_t		start;
	useconds_t		die;
	useconds_t		eat;
	useconds_t		sleep;
	int				time_to_eat;
	int				dead;
}	t_params;

void		fork_init(t_params *params);
t_params	*param_init(int ac, char **av);

void		*routine(t_params *params);

void    	ft_error(t_params *params);
int			ft_free(t_params **params);
int 		ft_atoi(char *s);

#endif
