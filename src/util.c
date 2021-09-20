/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:40:22 by semin             #+#    #+#             */
/*   Updated: 2021/09/21 01:56:39 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

void	split_free(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

int	is_valid_extension(char *filename)
{
	char	**ret;
	char	*extension;
	char	ret_ptr;

	extension = "ber";
	ret = ft_split(filename, '.');
	if (ft_strcmp(ret[1], extension) == 0)
	{
		split_free(ret);
		free(ret);
		return (0);
	}
	split_free(ret);
	return (1);
}

void	put_image(t_ptrs *ptrs, t_image object, int x, int y)
{
	mlx_put_image_to_window(ptrs->mlx, ptrs->win, object.image, x, y);
}

t_params	*params_init(t_ptrs *ptrs, t_image *object, t_coo *coo)
{
	t_params	*params;

	params = (t_params *)malloc(sizeof(t_params));
	params->ptrs = ptrs;
	params->object = object;
	params->coo = coo;
	params->coo->item = 0;
	params->C = 0;
	params->P = 0;
	params->E = 0;
	params->key = 2;
	params->move = 0;
	return (params);
}
