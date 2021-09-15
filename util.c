/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:27:28 by semin             #+#    #+#             */
/*   Updated: 2021/06/26 16:28:10 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}

void	ft_putnbr_base(unsigned long long num, t_data *data)
{
	char	c;

	if (num > 0)
	{
		ft_putnbr_base(num / 16, data);
		c = "0123456789abcdef"[num % 16];
		if (data->type == 7)
			c = ft_toupper(c);
		write(1, &c, 1);
	}
}

int		ft_unumlen(unsigned long long num)
{
	int	ret;

	ret = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		ret++;
	}
	return (ret);
}

int		ft_xnumlen(unsigned long long num)
{
	int	ret;

	ret = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		ret++;
	}
	return (ret);
}

void	ft_uputnbr(unsigned long long num)
{
	char	c;

	if (num < 0)
		num *= -1;
	if (num > 0)
	{
		ft_uputnbr(num / 10);
		c = num % 10 + '0';
		write(1, &c, 1);
	}
}
