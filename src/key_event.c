/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:46:36 by semin             #+#    #+#             */
/*   Updated: 2021/09/14 19:52:25 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_key(int keycode, t_params *params)
{
	if (keycode == KEY_W)
	{
		if (params->map[(params->coo->y - 1) / 30][params->coo->x / 30] != '1'
		&& params->map[(params->coo->y - 1) / 30][(params->coo->x + 29) / 30] != '1')
			params->coo->y -= 30;
	}
	if (keycode == KEY_A)
	{
		if (params->map[params->coo->y / 30][(params->coo->x - 1) / 30] != '1'
		&& params->map[(params->coo->y + 29) / 30][(params->coo->x - 1) / 30] != '1')
			params->coo->x -= 30;		
	}
	if (keycode == KEY_S)
	{
		if (params->map[(params->coo->y + 30) / 30][params->coo->x / 30] != '1'
		&& params->map[(params->coo->y + 30) / 30][(params->coo->x + 29) / 30] != '1')
			params->coo->y += 30;
	}
	if (keycode == KEY_D)
	{
		if (params->map[params->coo->y / 30][(params->coo->x + 30) / 30] != '1'
		&& params->map[(params->coo->y + 29) / 30][(params->coo->x + 30) / 30] != '1')
			params->coo->x += 30;
	}
	if (keycode == KEY_ESC)
		exit(0);
	if (params->map[params->coo->y / 30][params->coo->x / 30] == 'C')
		params->coo->item = 1;
	draw_map(params->map, params->ptrs, params->coo, params->object);
	return (0);
}
