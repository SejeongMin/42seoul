/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:57:21 by semin             #+#    #+#             */
/*   Updated: 2021/05/16 18:45:37 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	char	*new_ptr;
	int		i;

	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	i = size * count;
	new_ptr = ptr;
	while (i--)
	{
		*new_ptr = 0;
		new_ptr++;
	}
	return ((void *)ptr);
}
