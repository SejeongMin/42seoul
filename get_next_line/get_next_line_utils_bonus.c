/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:03:35 by semin             #+#    #+#             */
/*   Updated: 2021/05/27 17:25:32 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	int		len;

	len = ft_strlen(s1) + 1;
	s = (char *)malloc(len);
	if (!s)
		return (NULL);
	s[--len] = 0;
	len--;
	while (len >= 0)
	{
		s[len] = s1[len];
		len--;
	}
	return (s);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	dst_ptr = dst;
	src_ptr = (const unsigned char *)src;
	i = 0;
	while (i < len)
	{
		*dst_ptr = *src_ptr;
		dst_ptr++;
		src_ptr++;
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(s = (char *)malloc(s1_len + s2_len + 1)))
		return (NULL);
	ft_memcpy(s, s1, s1_len);
	ft_memcpy(s + s1_len, s2, s2_len);
	*(s + s1_len + s2_len) = 0;
	return (s);
}
