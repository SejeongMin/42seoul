/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:48 by semin             #+#    #+#             */
/*   Updated: 2021/11/30 18:43:52 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philosophers(t_params *params)
{
	int		i;
	t_philo	*philo;
	int		ret;

	philo = params->philo;
	params->start = get_time();
	i = 0;
	while (i < params->philo_num && params->dead == 0)
	{
		philo[i].num = i + 1;
		philo[i].eating = 0;
		philo[i].last_ate = params->start;
		params->cur_num = i;
		if (pthread_create(&(philo[i].pthread), 0, (void *)routine, params))
		{
			ft_error(params);
			break;
		}
		usleep(10);
		i++;
	}
}

int	main(int ac, char **av)
{
	pthread_t		*philosopher;
	t_params		*params;
	int				philo_num;

	if (ac < 5 || ac > 6)
		return (1);
	params = param_init(ac, av);
	create_philosophers(params);
	philo_num = params->philo_num;
	while (--philo_num >= 0)
	{
		pthread_join(params->philo[philo_num].pthread, 0);
	}
	ft_free(&(params));
}
