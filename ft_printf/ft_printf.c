/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:57:26 by semin             #+#    #+#             */
/*   Updated: 2021/06/26 16:40:14 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_find(char *str, char c)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (c == *tmp)
			return (tmp);
		tmp++;
	}
	return (NULL);
}

static void	check_data(t_data *data)
{
	if (data->type == 3 && data->prec >= 0)
		data->zero = 0;
	if ((data->type == 4 || data->type == 5) && data->prec >= 0)
		data->zero = 0;
	if ((data->type == 6 || data->type == 7) && data->prec >= 0)
		data->zero = 0;
	if (data->minus == 1)
		data->zero = 0;
}

static void	init_data(t_data *data)
{
	data->minus = 0;
	data->zero = 0;
	data->prec = -1;
	data->width = 0;
	data->type = 0;
}

static int	start_print(va_list ap, t_data *data)
{
	int	ret;

	ret = 0;
	check_data(data);
	if (data->type == 1)
		print_char(va_arg(ap, int), data, &ret);
	else if (data->type == 2)
		print_str(va_arg(ap, char *), data, &ret);
	else if (data->type == 3)
		print_p(va_arg(ap, unsigned long long), data, &ret);
	else if (data->type == 4)
		print_int(va_arg(ap, int), data, &ret);
	else if (data->type == 5)
		print_ux(va_arg(ap, unsigned int), data, &ret);
	else if (data->type == 6)
		print_ux(va_arg(ap, unsigned int), data, &ret);
	else if (data->type == 7)
		print_ux(va_arg(ap, unsigned int), data, &ret);
	else if (data->type == 8)
		print_char('%', data, &ret);
	return (ret);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		i;
	t_data	data;

	va_start(ap, format);
	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			init_data(&data);
			i++;
			i += ft_parsing((char*)(&format[i]), ap, &data);
			ret += start_print(ap, &data);
		}
		else
		{
			write(1, &format[i++], 1);
			ret++;
		}
	}
	va_end(ap);
	return (ret);
}
