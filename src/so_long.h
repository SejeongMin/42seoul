/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:58:00 by semin             #+#    #+#             */
/*   Updated: 2021/09/16 01:45:48 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "mlx.h"

int		is_valid_extension(char *filename);

typedef struct 	s_image{
	void	*image;
	int		width;
	int		height;
	int		x;
	int		y;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_ptrs{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_ptrs;

typedef struct	s_coo
{
	int	x;
	int	y;
	int	item;
}				t_coo;

typedef struct	s_params
{
	t_ptrs	*ptrs;
	t_image *object;
	t_coo	*coo;
	char	**map;
	int		C;
	int		P;
	int		E;
	int		key;
	int		move;
}				t_params;

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

# define KEY_PRESS_EVENT	2

int	input_key(int keycode, t_params *params);
void	draw_initial_map(char **map, t_ptrs *ptrs, t_coo *coo, t_image *object);
void	draw_map(char **map, t_params *params);

#endif
