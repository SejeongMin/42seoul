/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:24:06 by semin             #+#    #+#             */
/*   Updated: 2021/05/09 17:47:03 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (*dst && i < len)
	{
		dst++;
		i++;
	}
	while (*src && i + 1 < len)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	if (i < len)
		*dst = '\0';
	while (*src)
	{
		src++;
		i++;
	}
	return (i);
}
