/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:14:13 by semin             #+#    #+#             */
/*   Updated: 2021/09/13 20:38:47 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

// void	my_mlx_pixel_put(int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image floor;
	t_image circle;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1600, 1000, "so_long");
	floor.image = mlx_png_file_to_image(mlx_ptr, "../img/blue.png", &floor.width, &floor.height);
	circle.image = mlx_png_file_to_image(mlx_ptr, "../img/cat.png", &circle.width, &circle.height);

	mlx_put_image_to_window(mlx_ptr, win_ptr, floor.image, 30, 30);
	mlx_put_image_to_window(mlx_ptr, win_ptr, circle.image, 30, 30);

	mlx_loop(mlx_ptr);
	return (0);
}
