/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:03:49 by semin             #+#    #+#             */
/*   Updated: 2021/05/14 14:56:06 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_len(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*ret;
	long long	value;
	int			sign;
	int			len;

	value = (long long)n;
	len = get_len(value);
	sign = 1;
	if (value < 0)
	{
		sign *= -1;
		value *= -1;
	}
	if (!(ret = (char *)malloc(len + 1)))
		return (NULL);
	ret[len--] = 0;
	while (len >= 0)
	{
		ret[len--] = value % 10 + '0';
		value /= 10;
	}
	if (sign == -1)
		ret[0] = '-';
	return (ret);
}
