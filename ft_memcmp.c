/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:34:43 by semin             #+#    #+#             */
/*   Updated: 2021/05/07 14:46:05 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char	*ptr_b1;
	const unsigned char	*ptr_b2;

	ptr_b1 = b1;
	ptr_b2 = b2;
	while (len--)
	{
		if (*(ptr_b1) != *(ptr_b2))
			return ((int)(*ptr_b1 - *ptr_b2));
		ptr_b1++;
		ptr_b2++;
	}
	return (0);
}
