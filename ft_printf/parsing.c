/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:00:50 by semin             #+#    #+#             */
/*   Updated: 2021/06/26 16:26:14 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag(char *str, t_data *data)
{
	int	ret;

	ret = 0;
	while (ft_find(FLAG, *str))
	{
		if (*str == '-')
			data->minus = 1;
		else if (*str == '0')
			data->zero = 1;
		ret++;
		str++;
	}
	return (ret);
}

static int	ft_width(char *str, va_list ap, t_data *data)
{
	int		width;
	int		ret;

	width = 0;
	ret = 0;
	if (str[ret] == '*')
	{
		width = va_arg(ap, int);
		if (width < 0)
		{
			data->minus = 1;
			width = width * (-1);
		}
		ret++;
	}
	else
	{
		while ('0' <= str[ret] && str[ret] <= '9')
		{
			width = width * 10 + (str[ret] - '0');
			ret++;
		}
	}
	data->width = width;
	return (ret);
}

static int	ft_prec(char *str, va_list ap, t_data *data)
{
	int		prec;
	int		ret;

	prec = -1;
	ret = 0;
	if (str[ret] == '.')
	{
		prec = 0;
		ret++;
		if (str[ret] == '*')
		{
			prec = va_arg(ap, int);
			ret++;
		}
		else
			while ('0' <= str[ret] && str[ret] <= '9')
			{
				prec = prec * 10 + (str[ret] - '0');
				ret++;
			}
	}
	if (prec >= 0)
		data->prec = prec;
	return (ret);
}

static int	ft_type(char *str, t_data *data)
{
	if (*str == 'c')
		data->type = 1;
	else if (*str == 's')
		data->type = 2;
	else if (*str == 'p')
		data->type = 3;
	else if (*str == 'd' || *str == 'i')
		data->type = 4;
	else if (*str == 'u')
		data->type = 5;
	else if (*str == 'x')
		data->type = 6;
	else if (*str == 'X')
		data->type = 7;
	else if (*str == '%')
		data->type = 8;
	else
		return (0);
	return (1);
}

int			ft_parsing(char *str, va_list ap, t_data *data)
{
	int		idx;

	idx = 0;
	idx += ft_flag(&str[idx], data);
	idx += ft_width(&str[idx], ap, data);
	idx += ft_prec(&str[idx], ap, data);
	idx += ft_type(&str[idx], data);
	return (idx);
}
