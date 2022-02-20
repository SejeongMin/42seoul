/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:48 by semin             #+#    #+#             */
/*   Updated: 2021/12/21 17:09:56 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*death_check(t_params *params)
{
	int			i;
	useconds_t	gap;

	i = 0;
	while (params->dead == 0 || params->ate < params->philo_num)
	{
		gap = get_time() - params->philo[i].last_ate;
		if (gap > params->die && !params->philo[i].eating)
		{
			kill_philo(params, &params->philo[i]);
			break ;
		}
		i++;
		if (i >= params->philo_num)
			i = 0;
	}
	return (NULL);
}

void	create_philosophers(t_params *params)
{
	int			i;
	t_philo		*philo;
	int			ret;
	pthread_t	die_check;

	philo = params->philo;
	params->start = get_time();
	i = 0;
	while (i < params->philo_num && params->dead == 0)
	{
		philo[i].num = i + 1;
		philo[i].eating = 0;
		philo[i].last_ate = params->start;
		philo[i].ate = 0;
		params->cur_num = i;
		if (pthread_create(&(philo[i].pthread), 0, (void *)routine, params))
		{
			ft_error(params);
			break ;
		}
		usleep(10);
		i++;
	}
	pthread_create(&die_check, 0, (void *)death_check, params);
	pthread_detach(die_check);
}

int	main(int ac, char **av)
{
	pthread_t		*philosopher;
	t_params		*params;
	int				philo_num;

	if (ac < 5 || ac > 6)
		return (1);
	params = param_init(ac, av);
	if (!params)
		return (1);
	create_philosophers(params);
	philo_num = params->philo_num;
	while (--philo_num >= 0)
	{
		pthread_join(params->philo[philo_num].pthread, 0);
	}
	if (params->dead == 0 && params->philo_num > 0)
		printf("All philosophers survived!\n");
	destroy_mutex(params);
	ft_free(&(params));
}
