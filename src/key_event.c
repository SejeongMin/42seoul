/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:46:36 by semin             #+#    #+#             */
/*   Updated: 2021/09/15 01:02:50 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_key(int keycode, t_params *params)
{
	if (keycode == KEY_W)
	{
		if (params->map[(params->coo->y - 1) / 100][params->coo->x / 100] != '1'
		&& params->map[(params->coo->y - 1) / 100][(params->coo->x + 99) / 100] != '1')
			params->coo->y -= 100;
	}
	if (keycode == KEY_A)
	{
		if (params->map[params->coo->y / 100][(params->coo->x - 1) / 100] != '1'
		&& params->map[(params->coo->y + 99) / 100][(params->coo->x - 1) / 100] != '1')
			params->coo->x -= 100;		
	}
	if (keycode == KEY_S)
	{
		if (params->map[(params->coo->y + 100) / 100][params->coo->x / 100] != '1'
		&& params->map[(params->coo->y + 100) / 100][(params->coo->x + 99) / 100] != '1')
			params->coo->y += 100;
	}
	if (keycode == KEY_D)
	{
		if (params->map[params->coo->y / 100][(params->coo->x + 100) / 100] != '1'
		&& params->map[(params->coo->y + 99) / 100][(params->coo->x + 100) / 100] != '1')
			params->coo->x += 100;
	}
	if (keycode == KEY_ESC)
		exit(0);
	if (params->map[params->coo->y / 100][params->coo->x / 100] == 'C')
		params->coo->item = 1;
	draw_map(params->map, params->ptrs, params->coo, params->object);
	return (0);
}
