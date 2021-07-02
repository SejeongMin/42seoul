/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:33:35 by semin             #+#    #+#             */
/*   Updated: 2021/05/17 15:44:06 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(long long n, int fd)
{
	unsigned char	c;

	if (n / 10 != 0)
	{
		ft_putnbr(n / 10, fd);
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long long	value;

	if (fd < 0)
		return ;
	value = (long long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr(-value, fd);
	}
	else
		ft_putnbr(value, fd);
}
