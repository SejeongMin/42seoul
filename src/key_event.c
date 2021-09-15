/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:46:36 by semin             #+#    #+#             */
/*   Updated: 2021/09/16 01:50:09 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_key(int keycode, t_params *params)
{
	if (keycode == KEY_W)
	{
		if (params->map[(params->coo->y - 1) / 100][params->coo->x / 100] != '1'
		&& params->map[(params->coo->y - 1) / 100][(params->coo->x + 99) / 100] != '1')
		{
			params->coo->y -= 100;
			params->key = 4;
			params->move++;
			ft_printf("move: %d\n", params->move);
		}
	}
	if (keycode == KEY_A)
	{
		if (params->map[params->coo->y / 100][(params->coo->x - 1) / 100] != '1'
		&& params->map[(params->coo->y + 99) / 100][(params->coo->x - 1) / 100] != '1')
		{
			params->coo->x -= 100;
			params->key = 3;
			params->move++;
			ft_printf("move: %d\n", params->move);
		}
				
	}
	if (keycode == KEY_S)
	{
		if (params->map[(params->coo->y + 100) / 100][params->coo->x / 100] != '1'
		&& params->map[(params->coo->y + 100) / 100][(params->coo->x + 99) / 100] != '1')
		{
			params->coo->y += 100;
			params->key = 5;
			params->move++;
			ft_printf("move: %d\n", params->move);
		}
	}
	if (keycode == KEY_D)
	{
		if (params->map[params->coo->y / 100][(params->coo->x + 100) / 100] != '1'
		&& params->map[(params->coo->y + 99) / 100][(params->coo->x + 100) / 100] != '1')
		{
			params->coo->x += 100;
			params->key = 2;
			params->move++;
			ft_printf("move: %d\n", params->move);
		}
	}
	if (keycode == KEY_ESC)
		exit(0);
	if (params->map[params->coo->y / 100][params->coo->x / 100] == 'C')
		params->coo->item = 1;
	if (params->map[params->coo->y / 100][params->coo->x / 100] == 'E' && params->coo->item == 1)
	{
		ft_printf("Success");
		exit(0);
	}
	draw_map(params->map, params);
	return (0);
}
