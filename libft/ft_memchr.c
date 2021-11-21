/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:15:17 by semin             #+#    #+#             */
/*   Updated: 2021/05/07 14:33:41 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	const unsigned char	*ptr;
	unsigned char		value;

	value = c;
	ptr = (const unsigned char *)b;
	while (len--)
	{
		if (*ptr == value)
			return ((void *)ptr);
		ptr++;
	}
	return (0);
}
