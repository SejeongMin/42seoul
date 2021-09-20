/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:46:36 by semin             #+#    #+#             */
/*   Updated: 2021/09/21 01:48:35 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	key_w(t_params *params)
{
	if (params->map[(params->coo->y - 1) / 100][params->coo->x / 100] != '1')
	{
		params->coo->y -= 100;
		params->move++;
		ft_printf("move: %d\n", params->move);
	}
}

static void	key_a(t_params *params)
{
	params->key = 3;
	if (params->map[params->coo->y / 100][(params->coo->x - 1) / 100] != '1')
	{
		params->coo->x -= 100;
		params->move++;
		ft_printf("move: %d\n", params->move);
	}
}

static void	key_s(t_params *params)
{
	if (params->map[(params->coo->y + 100) / 100][params->coo->x / 100] != '1')
	{
		params->coo->y += 100;
		params->move++;
		ft_printf("move: %d\n", params->move);
	}
}

static void	key_d(t_params *params)
{
	params->key = 2;
	if (params->map[params->coo->y / 100][(params->coo->x + 100) / 100] != '1')
	{
		params->coo->x += 100;
		params->move++;
		ft_printf("move: %d\n", params->move);
	}
}

int	input_key(int keycode, t_params *params)
{
	if (keycode == KEY_W)
		key_w(params);
	if (keycode == KEY_A)
		key_a(params);
	if (keycode == KEY_S)
		key_s(params);
	if (keycode == KEY_D)
		key_d(params);
	if (keycode == KEY_ESC)
		ft_free(params, params->map, 0);
	if (params->map[params->coo->y / 100][params->coo->x / 100] == 'C')
		params->coo->item = 1;
	if (params->map[params->coo->y / 100][params->coo->x / 100] == 'E'
		&& params->coo->item == 1)
	{
		ft_printf("Success");
		ft_free(params, params->map, 0);
	}
	draw_map(params->map, params);
	return (0);
}
