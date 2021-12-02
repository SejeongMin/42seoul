/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:45:08 by semin             #+#    #+#             */
/*   Updated: 2021/12/02 15:52:36 by semin            ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t		pthread;
	int				num;
	useconds_t		last_ate;
	pthread_mutex_t	*f1;
	pthread_mutex_t	*f2;
	//mutex -> semaphore 로 바꾸기
	int				dead;
	int				eating;
	pthread_t		check;
	int				ate;
}	t_philo;

typedef struct s_params
{
	t_philo			*philo;
	// pthread_mutex_t	*forks;
	// pthread_mutex_t	print;
	// 여러개의 프로세스 생성 후 안에서 death돌리기
	// 세마포어가 2이상일 경우 포크를 집고 먹음
	// 죽을 경우 free 후 exit
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

useconds_t	get_time(void);
float		time_gap(t_params *params);
void		my_usleep(useconds_t wait);

void		ft_error(t_params *params);
int			ft_free(t_params **params);
int			ft_atoi(char *s, t_params *params);

void		destroy_mutex(t_params *params);
void		kill_philo(t_params *params, t_philo *philo);

#endif
