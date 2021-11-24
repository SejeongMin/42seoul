/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:48 by semin             #+#    #+#             */
/*   Updated: 2021/11/24 18:47:44 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_routine()
{
	printf("eat\n");
	printf("think\n");
	printf("sleep\n");
}

void	create_philosophers(pthread_t *philosopher, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		pthread_create(&philosopher[i], 0, (void *)philo_routine, 0);
	}
}

int main(int ac, char **av)
{
	pthread_mutex_t	mutex;
	pthread_t		*philosopher;
	int				philo_num;

	if (ac < 5)
		return (1);
	philo_num = ft_atoi(av[1]);
	philosopher = (pthread_t *)malloc(sizeof(pthread_t) * philo_num);
	if (pthread_mutex_init(&mutex, 0))
		ft_error();
	create_philosophers(philosopher, philo_num);
	
	// t_time	start, end;
	// gettimeofday(&start, 0);
	// sleep(1);
	// gettimeofday(&end, 0);
	// printf("%f s\n", end.tv_sec - start.tv_sec);
}
