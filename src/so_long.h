/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 16:58:00 by semin             #+#    #+#             */
/*   Updated: 2021/09/21 02:24:29 by semin            ###   ########.fr       */
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

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

# define KEY_PRESS_EVENT	2

typedef struct	s_image{
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
	void	*mlx;
	void	*win;
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
	t_image	*object;
	t_coo	*coo;
	char	**map;
	int		C;
	int		P;
	int		E;
	int		key;
	int		move;
}				t_params;

int			is_valid_extension(char *filename);

int			count_line(char *filename);
int			count_width(char *filename);
char		**map_parser(char *filename, t_params *params);
void		split_free(char **ret);

int			input_key(int keycode, t_params *params);
void		draw_initial_map(char **map, t_ptrs *ptrs, t_coo *coo, t_image *object);
void		draw_map(char **map, t_params *params);

void		put_image(t_ptrs *ptrs, t_image object, int x, int y);
t_params	*params_init(t_ptrs *ptrs, t_image *object, t_coo *coo);
void		ft_free(t_params *params, char **map, int errno);
int			close_win_x(t_params *params);
void		set_coo(t_coo *coo, int i, int j);
void		map_error(char **line);

#endif
