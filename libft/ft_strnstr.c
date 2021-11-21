/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:37:15 by semin             #+#    #+#             */
/*   Updated: 2021/05/15 15:09:24 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const unsigned char	*hay_ptr;
	size_t				nee_len;

	if (!haystack && !needle)
		return (NULL);
	if (!*needle)
		return ((char *)haystack);
	hay_ptr = (const unsigned char *)haystack;
	nee_len = ft_strlen(needle);
	while (*hay_ptr && nee_len <= len)
	{
		if (!ft_strncmp((const char *)hay_ptr, needle, nee_len))
			return ((char *)hay_ptr);
		hay_ptr++;
		len--;
	}
	return (NULL);
}
