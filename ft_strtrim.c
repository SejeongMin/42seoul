/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:42:23 by semin             #+#    #+#             */
/*   Updated: 2021/05/14 16:06:35 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (start != end && ft_strchr(set, s1[start]))
		start++;
	while (end != 0 && ft_strchr(set, s1[end]))
		end--;
	if (start >= end)
	{
		if (!(ret = (char *)malloc(1)))
			return (NULL);
		*ret = 0;
	}
	else
	{
		if (!(ret = (char *)malloc(end - start + 2)))
			return (NULL);
		ft_strlcpy(ret, &s1[start], end - start + 2);
	}
	return (ret);
}
