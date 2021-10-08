/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:16:57 by semin             #+#    #+#             */
/*   Updated: 2021/10/07 19:06:09 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *filename)
{
	char	**line;
	int		map_width;
	int		fd;
	int		ret;

	line = (char **)malloc(sizeof(char *));
	fd = open(filename, O_RDONLY);
	ret = 0;
	while (get_next_line(fd, line) > 0)
	{
		ret++;
	}
	close(fd);
	free(line);
	return (ret);
}

int	count_width(char *filename)
{
	char	**line;
	int		map_width;
	int		prev_width;
	int		idx;
	int		fd;

	line = (char **)malloc(sizeof(char *));
	idx = 0;
	fd = open(filename, O_RDONLY);
	prev_width = 0;
	map_width = 0;
	map_width = get_next_line(fd, line);
	while (map_width > 0)
	{
		if (idx != 0 && map_width != prev_width)
			map_error(line);
		idx++;
		prev_width = map_width;
		map_width = get_next_line(fd, line);
	}
	close(fd);
	free(line);
	return (prev_width);
}

static int	find_chr(const char *s, int c)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			ret++;
		s++;
	}
	return (ret);
}

static void	valid_check(char **map, t_params *params, int idx, int lines)
{
	int		map_width;
	int		ret;
	int		ret2;
	char	*s;

	s = map[idx];
	map_width = ft_strlen(s);
	ret = 0;
	if (idx == 0 || idx + 1 == lines)
	{
		ret += find_chr(s, '1');
		if (ret != map_width)
			ft_free(params, map, 1);
	}
	else
	{
		if (s[0] != '1' || s[map_width - 1] != '1')
			ft_free(params, map, 1);
		ret += find_chr(s, '0') + find_chr(s, 'P') + find_chr(s, 'C');
		ret += find_chr(s, 'E') + find_chr(s, '1');
		if (ret != map_width)
			ft_free(params, map, 3);
	}
	params->P += find_chr(s, 'P');
	params->C += find_chr(s, 'C');
	params->E += find_chr(s, 'E');
}

char	**map_parser(char *filename, t_params *params)
{
	char	**ret;
	int		idx;
	int		lines;
	int		map_width;
	int		fd;

	idx = 0;
	map_width = count_width(filename);
	lines = count_line(filename);
	fd = open(filename, O_RDONLY);
	ret = (char **)malloc(sizeof(char *) * (lines + 1));
	while (idx < lines)
	{
		ret[idx] = (char *)malloc(sizeof(char) * (map_width + 1));
		ret[idx + 1] = 0;
		get_next_line(fd, &ret[idx]);
		valid_check(ret, params, idx, lines);
		idx++;
	}
	ret[idx] = 0;
	close(fd);
	if (params->C == 0 || params->P != 1 || params->E != 1)
		ft_free(params, ret, 2);
	return (ret);
}
