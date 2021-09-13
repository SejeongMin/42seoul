/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:46:36 by semin             #+#    #+#             */
/*   Updated: 2021/09/14 01:07:59 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	input_key(int keycode, t_params *params)
{
	if (keycode == KEY_W)
	{
		if (params->map[params->coo->y / 30][params->coo->x / 30] != '1')
			params->coo->y--;
	}
	if (keycode == KEY_A)
	{
		if (params->map[params->coo->y / 30][params->coo->x / 30] != '1')
			params->coo->x--;		
	}
	if (keycode == KEY_S)
	{
		if (params->map[(params->coo->y + 31) / 30][params->coo->x / 30] != '1')
			params->coo->y++;
	}
	if (keycode == KEY_D)
	{
		if (params->map[params->coo->y / 30][(params->coo->x + 31) / 30] != '1')
			params->coo->x++;
	}
	if (keycode == KEY_ESC)
		exit(0);
	draw_map(params->map, params->ptrs, params->coo, params->object);
	return (0);
}
