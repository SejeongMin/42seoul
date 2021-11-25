/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:48 by semin             #+#    #+#             */
/*   Updated: 2021/11/26 00:27:08 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*philo_routine(t_params *params)
{	
	// pthread_mutex_lock(&(params->mutex));
	params->num++;
	printf("num= %d\n", params->num);
	printf("eat\n");
	printf("think\n");
	printf("sleep\n");
	// pthread_mutex_unlock(&(params->mutex));
	return (NULL);
}

void	create_philosophers(pthread_t *p, int num, t_params *params)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_lock(&(params->mutex));
		pthread_create(&p[i], 0, (void *)philo_routine, params);
		pthread_mutex_unlock(&(params->mutex));

		i++;
	}
}

int main(int ac, char **av)
{
	pthread_t		*philosopher;
	t_params		*params;
	int				philo_num;

	if (ac < 5)
		return (1);
	params = (t_params *)malloc(sizeof(t_params));
	params->num = 0;
	philo_num = ft_atoi(av[1]);
	philosopher = (pthread_t *)malloc(sizeof(pthread_t) * philo_num);
	if (pthread_mutex_init(&(params->mutex), 0))
		ft_error();
	create_philosophers(philosopher, philo_num, params);
	
	pthread_mutex_destroy(&(params->mutex));
	free(params);
	
	// t_time	start, end;
	// gettimeofday(&start, 0);
	// sleep(1);
	// gettimeofday(&end, 0);
	// printf("%f s\n", end.tv_sec - start.tv_sec);
}
