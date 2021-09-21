/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:46:27 by semin             #+#    #+#             */
/*   Updated: 2021/09/21 21:11:27 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(long long num)
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

static void	ft_putnbr(long long num)
{
	char	c;

	if (num < 0)
		num *= -1;
	if (num > 0)
	{
		ft_putnbr(num / 10);
		c = num % 10 + '0';
		write(1, &c, 1);
	}
}

static void	print_left(long long num, int zero_len, int space_len, t_data *data)
{
	if (num < 0)
		write(1, "-", 1);
	while (zero_len--)
		write(1, "0", 1);
	if (num == 0 && data->prec != 0)
		write(1, "0", 1);
	else
		ft_putnbr(num);
	while (space_len--)
		write(1, " ", 1);
}

static void	print_right(long long num, int zero_len, int space_len,
						t_data *data)
{
	while (space_len--)
		write(1, " ", 1);
	if (num < 0)
		write(1, "-", 1);
	while (zero_len--)
		write(1, "0", 1);
	if (num == 0 && data->prec != 0)
		write(1, "0", 1);
	else
		ft_putnbr(num);
}

void	print_int(long long num, t_data *data, int *ret)
{
	int	zero_len;
	int	space_len;
	int	num_len;

	num_len = ft_numlen(num);
	if (num == 0 && data->prec == 0)
		num_len = 0;
	zero_len = 0;
	space_len = 0;
	if (data->prec > num_len)
		zero_len = data->prec - num_len;
	if (num < 0)
		num_len++;
	if (data->zero == 1 && data->width > num_len)
		zero_len = data->width - num_len;
	if (data->width > zero_len + num_len)
		space_len = data->width - zero_len - num_len;
	if (data->minus == 0)
		print_right(num, zero_len, space_len, data);
	else
		print_left(num, zero_len, space_len, data);
	*ret += space_len + zero_len + num_len;
}
