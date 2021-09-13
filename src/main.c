/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:40:09 by semin             #+#    #+#             */
/*   Updated: 2021/09/13 21:54:14 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	count_line(char *filename)
{
	char	**line;
	int		map_width;
	int		prev_width;
	int		idx;
	int		fd;
	int		ret;

	line = (char**)malloc(sizeof(char*));
	idx = 0;
	fd = open(filename, O_RDONLY);
	prev_width = 0;
	ret = 0;
	while ((map_width = get_next_line(fd, line)) > 0)
	{
		if (idx != 0 && map_width != prev_width)
			exit(1);
		ret++;
		idx++;
		prev_width = map_width;
	}
	close(fd);
	return (ret);
}

int	count_width(char *filename)
{
	char	**line;
	int		map_width;
	int		prev_width;
	int		idx;
	int		fd;
	int		ret;

	line = (char**)malloc(sizeof(char*));
	idx = 0;
	fd = open(filename, O_RDONLY);
	prev_width = 0;
	map_width = 0;
	ret = 0;
	while ((map_width = get_next_line(fd, line)) > 0)
	{
		if (idx != 0 && map_width != prev_width)
			exit(1);
		ret++;
		idx++;
		prev_width = map_width;
	}
	close(fd);
	return (prev_width);
}

char	**map_parser(char *filename)
{
	char	**ret;
	int		idx;
	int		lines;
	int		map_width;
	int		fd;

	idx = 0;
	lines = count_line(filename);
	map_width = count_width(filename);
	fd = open(filename, O_RDONLY);
	ret = (char**)malloc(sizeof(char*) * (lines + 1));
	while (idx < lines)
	{
		ret[idx] = (char*)malloc(sizeof(char) * (map_width + 1));
		get_next_line(fd, &ret[idx]);
		printf("%s\n", ret[idx]); //지우기~
		idx++;
	}
	ret[idx] = 0;
	close(fd);
	return (ret);
}

t_image	*save_image(t_ptrs *ptrs)
{
	t_image	*object;

	object = (t_image*)malloc(sizeof(t_image) * 9);
	object[0].image = mlx_xpm_file_to_image(ptrs->mlx_ptr, "../img/plank.xpm", &object[0].width, &object[0].height); //배경
	object[1].image = mlx_xpm_file_to_image(ptrs->mlx_ptr, "../img/wall.xpm", &object[1].width, &object[1].height); //벽
	object[2].image = mlx_xpm_file_to_image(ptrs->mlx_ptr, "../img/wall.xpm", &object[2].width, &object[2].height); //사람오른쪽
	object[3].image = mlx_png_file_to_image(ptrs->mlx_ptr, "../img/blue.png", &object[3].width, &object[3].height); //사람왼쪽
	object[4].image = mlx_png_file_to_image(ptrs->mlx_ptr, "../img/blue.png", &object[4].width, &object[4].height); //사람위
	object[5].image = mlx_png_file_to_image(ptrs->mlx_ptr, "../img/blue.png", &object[5].width, &object[5].height); //사람아래
	object[6].image = mlx_xpm_file_to_image(ptrs->mlx_ptr, "../img/bear_plank.xpm", &object[6].width, &object[6].height); //먹는거
	object[7].image = mlx_png_file_to_image(ptrs->mlx_ptr, "../img/blue.png", &object[7].width, &object[7].height); //출구
	object[7].image = mlx_png_file_to_image(ptrs->mlx_ptr, "../img/blue.png", &object[7].width, &object[7].height); //적
	return (object);
	//나중에 free?
}

void	draw_character(t_ptrs *ptrs, t_coo *coo, t_image character)
{
	mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, character.image, coo->x, coo->y);
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
			mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, object[0].image, j * 30, i * 30);
			if (map[i][j] == '1')
				mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, object[1].image, j * 30, i * 30);
			if (map[i][j] == 'P')
			{
				coo->x = j * 30;
				coo->y = i * 30;
				draw_character(ptrs, coo, object[2]);
			}
			if (map[i][j] == 'C')
				mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, object[6].image, j * 30, i * 30);
			j++;
		}
		i++;
	}
}

void	draw_map(char **map, t_ptrs *ptrs, t_coo *coo, t_image *object)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, object[0].image, j * 30, i * 30);
			if (map[i][j] == '1')
				mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, object[1].image, j * 30, i * 30);
			
			if (map[i][j] == 'C')
				mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, object[6].image, j * 30, i * 30);
			j++;
		}
		i++;
	}
	draw_character(ptrs, coo, object[2]);
}

t_params	*params_init(t_ptrs *ptrs, t_image *object, t_coo *coo, char **map)
{
	t_params	*params;

	params = (t_params*)malloc(sizeof(t_params));
	params->ptrs = ptrs;
	params->object = object;
	params->coo = coo;
	params->map = map;
	return (params);
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
	ptrs.mlx_ptr = mlx_init();
	ptrs.win_ptr = mlx_new_window(ptrs.mlx_ptr, count_width(av[1]) * 30, count_line(av[1]) * 30, "so_long");
	object = save_image(&ptrs);
	map = map_parser(av[1]);

	params = params_init(&ptrs, object, &coo, map);
	draw_initial_map(map, params->ptrs, params->coo, params->object);
	mlx_hook(ptrs.win_ptr, KEY_PRESS_EVENT, 0, &input_key, params);
	mlx_loop(ptrs.mlx_ptr);
	return (0);
}
