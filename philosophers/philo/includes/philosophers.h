/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:45:08 by semin             #+#    #+#             */
/*   Updated: 2021/11/27 01:43:32 by semin            ###   ########.fr       */
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

typedef struct s_time
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}	t_time;

typedef struct	s_philo
{
	pthread_t		pthread;
	pthread_mutex_t	mutex;
	int				num;
	struct timeval	last_ate;
	int				f1;
	int				f2;
	int				dead;
}	t_philo;

typedef struct	s_params
{
	t_philo		*philo;
	int			*forks;
	int			philo_num;
	int			cur_num;
	useconds_t	die;
	useconds_t	eat;
	useconds_t	sleep;
	int			time_to_eat;
}	t_params;


void    ft_error(t_params *params);
int		ft_free(t_params **params);

int 	ft_atoi(char *s);

#endif
