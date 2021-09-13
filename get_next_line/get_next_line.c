/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:28:13 by semin             #+#    #+#             */
/*   Updated: 2021/09/14 01:24:10 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	to_line(char **repo, char **line)
{
	char	*nl_ptr;
	char	*tmp_repo;

	if (*repo == NULL)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	nl_ptr = ft_strchr(*repo, '\n');
	tmp_repo = *repo;
	if (nl_ptr)
	{
		*nl_ptr = '\0';
		if (!(*line = ft_strdup(tmp_repo)))
			return (-1);
		if (!(tmp_repo = ft_strdup(nl_ptr + 1)))
			return (-1);
		free(*repo);
		*repo = tmp_repo;
		return (ft_strlen(*line));
	}
	*line = *repo;
	*repo = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*repo;
	char		*tmp_repo;
	char		buf[11];
	int			ret;

	if (fd > 255 || !line || fd < 0)
		return (-1);
	while ((ret = read(fd, buf, 10)) != 0)
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmp_repo = repo ? ft_strjoin(repo, buf) : ft_strdup(buf);
		if (!tmp_repo)
			return (-1);
		free(repo);
		repo = tmp_repo;
		if (ft_strchr(repo, '\n') != NULL)
			break ;
	}
	return (to_line(&repo, line));
}
