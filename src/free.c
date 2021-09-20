/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:52:41 by semin             #+#    #+#             */
/*   Updated: 2021/09/21 02:24:22 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_coo(t_coo *coo, int i, int j)
{
	coo->x = j * 100;
	coo->y = i * 100;
}

void	map_error(char **line)
{
	free(line);
	ft_printf("Error\nMap must be rectangular.");
	exit(1);
}

int	close_win_x(t_params *params)
{
	ft_free(params, params->map, 0);
	return (0);
}

void	ft_free(t_params *params, char **map, int errno)
{
	split_free(map);
	free(params->object);
	free(params);
	if (errno == 1)
	{
		ft_printf("Error\nMap must be surrounded by walls.");
		exit(1);
	}
	if (errno == 2)
	{
		ft_printf("Error\nMap must have at least one E, one C, and one P.");
		exit(1);
	}
	exit(0);
}
