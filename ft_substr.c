/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:05:58 by semin             #+#    #+#             */
/*   Updated: 2021/05/15 16:17:31 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (!(sub_s = (char *)malloc(len + 1)))
		return (NULL);
	if (start >= ft_strlen(s))
	{
		*sub_s = 0;
		return (sub_s);
	}
	ft_strlcpy(sub_s, &s[start], len + 1);
	return (sub_s);
}
