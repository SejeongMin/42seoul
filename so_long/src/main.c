/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:40:09 by semin             #+#    #+#             */
/*   Updated: 2021/09/26 23:10:04 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*xpm_handle(t_ptrs *ptrs, t_image *object, char *filename)
{
	int	width;
	int	height;

	width = object->width;
	height = object->height;
	return (mlx_xpm_file_to_image(ptrs->mlx, filename, &width, &height));
}

t_image	*save_image(t_ptrs *ptrs)
{
	t_image	*object;

	object = (t_image *)malloc(sizeof(t_image) * 8);
	object[0].image = xpm_handle(ptrs, &object[0], "../img/floor.xpm");
	object[1].image = xpm_handle(ptrs, &object[1], "../img/caution.xpm");
	object[2].image = xpm_handle(ptrs, &object[2], "../img/right.xpm");
	object[3].image = xpm_handle(ptrs, &object[3], "../img/left.xpm");
	object[4].image = xpm_handle(ptrs, &object[4], "../img/backward.xpm");
	object[5].image = xpm_handle(ptrs, &object[5], "../img/forward.xpm");
	object[6].image = xpm_handle(ptrs, &object[6], "../img/dead.xpm");
	object[7].image = xpm_handle(ptrs, &object[7], "../img/exit.xpm");
	return (object);
}

void	draw_initial_map(char **map, t_ptrs *ptrs, t_coo *coo, t_image *object)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			put_image(ptrs, object[0], j * 100, i * 100);
			if (map[i][j] == '1')
				put_image(ptrs, object[1], j * 100, i * 100);
			else if (map[i][j] == 'P')
			{
				set_coo(coo, i, j);
				put_image(ptrs, object[2], coo->x, coo->y);
			}
			else if (map[i][j] == 'C')
				put_image(ptrs, object[6], j * 100, i * 100);
			else if (map[i][j] == 'E')
				put_image(ptrs, object[7], j * 100, i * 100);
			j++;
		}
		i++;
	}
}

void	draw_map(char **map, t_params *params)
{
	int		i;
	int		j;
	t_ptrs	*ptrs;
	t_coo	*coo;

	coo = params->coo;
	ptrs = params->ptrs;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			put_image(ptrs, params->object[0], j * 100, i * 100);
			if (map[i][j] == '1')
				put_image(ptrs, params->object[1], j * 100, i * 100);
			if (map[i][j] == 'C')
				put_image(ptrs, params->object[6], j * 100, i * 100);
			if (map[i][j] == 'E')
				put_image(ptrs, params->object[7], j * 100, i * 100);
			j++;
		}
		i++;
	}
	put_image(ptrs, params->object[params->key], coo->x, coo->y);
}

int	main(int ac, char **av)
{
	char		**map;
	t_ptrs		ptrs;
	t_coo		coo;
	t_image		*object;
	t_params	*params;

	if (ac != 2)
		return (0);
	if (is_valid_extension(av[1]) == 0)
		return (1);
	ptrs.mlx = mlx_init();
	ptrs.win = mlx_new_window(ptrs.mlx, count_width(av[1]) * 100,
			count_line(av[1]) * 100, "so_long");
	object = save_image(&ptrs);
	params = params_init(&ptrs, object, &coo);
	map = map_parser(av[1], params);
	params->map = map;
	draw_initial_map(map, params->ptrs, params->coo, params->object);
	mlx_hook(ptrs.win, KEY_PRESS_EVENT, 0, &input_key, params);
	mlx_hook(ptrs.win, 17, 1L << 17, close_win_x, params);
	mlx_loop(ptrs.mlx);
	return (0);
}
