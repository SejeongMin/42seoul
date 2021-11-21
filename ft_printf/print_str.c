/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:46:29 by semin             #+#    #+#             */
/*   Updated: 2021/06/26 14:52:54 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		ret++;
		str++;
	}
	return (ret);
}

void		print_char(char c, t_data *data, int *ret)
{
	int	zero_len;
	int	space_len;

	zero_len = 0;
	space_len = 0;
	if (data->zero == 1 && data->width > 1)
		zero_len = data->width - 1;
	else if (data->zero == 0 && data->width > 1)
		space_len = data->width - 1;
	*ret = *ret + zero_len + space_len + 1;
	if (data->minus == 0)
	{
		while (zero_len--)
			write(1, "0", 1);
		while (space_len--)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	else
	{
		write(1, &c, 1);
		while (space_len--)
			write(1, " ", 1);
	}
}

static void	print_str2(char *str, t_data *data, int zero_len, int space_len)
{
	int	str_len;

	if (data->prec > ft_strlen(str) || data->prec == -1)
		str_len = ft_strlen(str);
	else
		str_len = data->prec;
	if (data->minus == 0)
	{
		while (zero_len--)
			write(1, "0", 1);
		while (space_len--)
			write(1, " ", 1);
		write(1, str, str_len);
	}
	else
	{
		write(1, str, str_len);
		while (space_len--)
			write(1, " ", 1);
	}
}

void		print_str(char *str, t_data *data, int *ret)
{
	int	zero_len;
	int	space_len;
	int	str_len;

	if (str == NULL)
		str = "(null)";
	zero_len = 0;
	space_len = 0;
	if (data->prec > ft_strlen(str) || data->prec == -1)
		str_len = ft_strlen(str);
	else
		str_len = data->prec;
	if (data->zero == 1 && data->width > str_len)
		zero_len = data->width - str_len;
	else if (data->zero == 0 && data->width > str_len)
		space_len = data->width - str_len;
	*ret = *ret + zero_len + space_len + str_len;
	print_str2(str, data, zero_len, space_len);
}
