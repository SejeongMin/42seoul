/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 18:11:44 by semin             #+#    #+#             */
/*   Updated: 2021/05/07 14:28:15 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	const unsigned char	*src_ptr;
	unsigned char		*dst_ptr;
	size_t				i;
	unsigned char		value;

	src_ptr = (const unsigned char *)src;
	dst_ptr = dst;
	value = c;
	i = 0;
	while (i < len)
	{
		*dst_ptr = *src_ptr;
		if (*dst_ptr == value)
			return (dst_ptr + 1);
		dst_ptr++;
		src_ptr++;
		i++;
	}
	return (0);
}
