/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:47:09 by semin             #+#    #+#             */
/*   Updated: 2021/05/08 17:50:28 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
