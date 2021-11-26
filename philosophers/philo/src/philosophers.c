/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:48 by semin             #+#    #+#             */
/*   Updated: 2021/11/27 01:45:19 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(t_params *params)
{
	//eat->sleep->think  ->eat->sleep->think
	int	num;
	int	*forks;
	int	f1;
	int	f2;

	num = params->cur_num;
	forks = params->forks;
	f1 = params->philo[num].f1;
	f2 = params->philo[num].f2;
	while (params->philo[num].dead != 0)
	{
		if (forks[f1] == 0 && forks[f2] == 0)
		{
			pthread_mutex_lock(&(params->philo[num].mutex));
			forks[f1] = 1;
			printf("%d has taken a fork\n", num + 1);
			forks[f2] = 1;
			printf("%d has taken a fork\n", num + 1);
			printf("%d is eating\n", num + 1);
			// pthread_mutex_unlock(&(params->philo[params->cur_num].mutex));
			usleep(params->eat);
			// pthread_mutex_lock(&(params->philo[params->cur_num].mutex));
			forks[f1] = 0;
			forks[f2] = 0;
			pthread_mutex_unlock(&(params->philo[params->cur_num].mutex));
		}
		printf("%d is sleeping\n", num + 1);
		usleep(params->sleep);
		if (forks[f1] == 1 || forks[f2] == 1)
		{
			printf("%d is thinking\n", num + 1);
			while (forks[f1] == 1 || forks[f2] == 1)
			{}
		}
	}
	return (NULL);
}

void	create_philosophers(t_params *params)
{
	int		i;
	t_philo	*philo;
	int		ret;

	philo = params->philo;
	i = 0;
	while (i < params->philo_num)
	{
		params->cur_num = i;
		philo[i].num = i + 1;
		if (i == 0)
			philo[i].f1 = params->philo_num - 1;
		else
			philo[i].f1 = i - 1;
		philo[i].dead = 0;
		philo[i].f2 = i;
		if (pthread_create(&(philo[i].pthread), 0, (void *)routine, params))
			ft_error(params);
		i++;
	}
}

t_params	*param_init(int ac, char **av)
{
	t_params	*params;
	int			num;

	num = ft_atoi(av[1]);
	params = (t_params *)malloc(sizeof(t_params));
	params->philo_num = num;
	params->cur_num = -1;
	params->die = ft_atoi(av[2]) * 1000;
	params->eat = ft_atoi(av[3]) * 1000;
	params->sleep = ft_atoi(av[4]) * 1000;
	if (ac == 6)
		params->time_to_eat = ft_atoi(av[5]);
	else
		params->time_to_eat = -1;
	params->forks = (int *)malloc(sizeof(int) * num);
	params->philo = (t_philo *)malloc(sizeof(t_philo) * num);
	while (--num >= 0)
	{
		params->forks[num] = 0;
		if (pthread_mutex_init(&(params->philo[num].mutex), 0))
			ft_error(params);
	}
	return (params);
}

void	destroy_mutex(t_params *params)
{
	int	num;

	num = params->philo_num;
	while (--num >= 0)
	{
		pthread_mutex_destroy(&(params->philo[num].mutex));
	}
}

int	ft_free(t_params **params)
{
	free((*params)->forks);
	free((*params)->philo);
	free(*params);
	return (0);
}

int main(int ac, char **av)
{
	pthread_t		*philosopher;
	t_params		*params;
	int				philo_num;

	if (ac < 5 || ac > 6)
		return (1);
	params = param_init(ac, av);
	create_philosophers(params);
	philo_num = params->philo_num;
	// while (--philo_num >= 0)
	// {
	// 	pthread_join(params->philo[philo_num].pthread, 0);
	// }
	ft_free(&(params));
}
