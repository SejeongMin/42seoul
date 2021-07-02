/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:35:51 by semin             #+#    #+#             */
/*   Updated: 2021/05/11 19:43:49 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
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
