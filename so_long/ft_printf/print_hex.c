/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:53:03 by semin             #+#    #+#             */
/*   Updated: 2021/09/21 21:09:02 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	printux_left(unsigned long long num, int zero_len,
					int space_len, t_data *data)
{
	while (zero_len--)
		write(1, "0", 1);
	if (num == 0 && data->prec != 0)
	{
		if (data->type == 3)
			ft_printf("0x");
		write(1, "0", 1);
	}
	else
	{
		if (data->type == 5)
			ft_uputnbr(num);
		else
		{
			if (data->type == 3)
				ft_printf("0x");
			ft_putnbr_base(num, data);
		}
	}
	while (space_len--)
		write(1, " ", 1);
}

static void	printux_right(unsigned long long num, int zero_len,
					int space_len, t_data *data)
{
	while (space_len--)
		write(1, " ", 1);
	if (data->type == 3)
		ft_printf("0x");
	while (zero_len--)
		write(1, "0", 1);
	if (num == 0 && data->prec != 0)
		write(1, "0", 1);
	else
	{
		if (data->type == 5)
			ft_uputnbr(num);
		else
			ft_putnbr_base(num, data);
	}
}

void	print_ux(unsigned long long num, t_data *data, int *ret)
{
	int	zero_len;
	int	space_len;
	int	num_len;

	if (data->type == 5)
		num_len = ft_unumlen(num);
	else
		num_len = ft_xnumlen(num);
	if (num == 0 && data->prec == 0)
		num_len = 0;
	zero_len = 0;
	space_len = 0;
	if (data->prec > num_len)
		zero_len = data->prec - num_len;
	if (data->zero == 1 && data->width > num_len)
		zero_len = data->width - num_len;
	if (data->width > zero_len + num_len)
		space_len = data->width - zero_len - num_len;
	if (data->minus == 0)
		printux_right(num, zero_len, space_len, data);
	else
		printux_left(num, zero_len, space_len, data);
	*ret += space_len + zero_len + num_len;
}

void	print_p(unsigned long long num, t_data *data, int *ret)
{
	int	zero_len;
	int	space_len;
	int	num_len;

	num_len = ft_xnumlen(num);
	if (num == 0 && data->prec == 0)
		num_len = 0;
	if (data->width > data->prec && data->width > num_len)
		num_len += 2;
	else
		*ret += 2;
	zero_len = 0;
	space_len = 0;
	if (data->prec > num_len)
		zero_len = data->prec - num_len;
	if (data->zero == 1 && data->width > num_len)
		zero_len = data->width - num_len;
	if (data->width > zero_len + num_len)
		space_len = data->width - zero_len - num_len;
	if (data->minus == 0)
		printux_right(num, zero_len, space_len, data);
	else
		printux_left(num, zero_len, space_len, data);
	*ret += space_len + zero_len + num_len;
}
