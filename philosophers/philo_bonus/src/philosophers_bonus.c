/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:07:48 by semin             #+#    #+#             */
/*   Updated: 2021/12/06 22:27:25 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	create_philosophers(t_params *params)
{
	int		i;
	t_philo	*philo;

	philo = params->philo;
	params->start = get_time();
	i = 0;
	while (i < params->philo_num && params->dead == 0)
	{
		philo[i].num = i + 1;
		philo[i].eating = 0;
		philo[i].ate = 0;
		params->cur_num = i;
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			routine(params, &philo[i]);
		}
		usleep(50);
		i++;
	}
}

int	main(int ac, char **av)
{
	pthread_t	*philosopher;
	t_params	*params;
	int			philo_num;
	int			status;

	if (ac < 5 || ac > 6)
		return (1);
	params = param_init(ac, av);
	create_philosophers(params);
	waitpid(-1, &status, 0);
	philo_num = params->philo_num;
	if (status == 0)
		printf("All philosophers survived!\n");
	ft_free(&(params));
}
