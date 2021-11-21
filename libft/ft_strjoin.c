/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:25:38 by semin             #+#    #+#             */
/*   Updated: 2021/05/14 15:53:49 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		s1_len;
	int		s2_len;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(s = (char *)malloc(s1_len + s2_len + 1)))
		return (NULL);
	ft_memcpy(s, s1, s1_len);
	ft_memcpy(s + s1_len, s2, s2_len);
	*(s + s1_len + s2_len) = 0;
	return (s);
}
