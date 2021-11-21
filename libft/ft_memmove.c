/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:52:14 by semin             #+#    #+#             */
/*   Updated: 2021/05/07 14:45:17 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ptr;
	const unsigned char	*src_ptr;

	if (src == dst || len == 0)
		return (dst);
	if (src < dst)
	{
		dst_ptr = dst + len - 1;
		src_ptr = src + len - 1;
		while (len--)
			*(dst_ptr--) = *(src_ptr--);
	}
	else
	{
		dst_ptr = dst;
		src_ptr = src;
		while (len--)
			*(dst_ptr++) = *(src_ptr++);
	}
	return (dst);
}
