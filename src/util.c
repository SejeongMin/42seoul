/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:40:22 by semin             #+#    #+#             */
/*   Updated: 2021/09/13 21:53:59 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int ft_strcmp(const char *s1, const char *s2)
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

static void	split_free(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
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
	free(ret);
	return (1);
}
