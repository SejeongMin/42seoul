/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:45:08 by semin             #+#    #+#             */
/*   Updated: 2021/11/26 00:04:59 by semin            ###   ########.fr       */
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

typedef struct	s_params
{
	pthread_mutex_t mutex;
	int				num;
}	t_params;


void    ft_error();
int 	ft_atoi(char *s);

#endif
