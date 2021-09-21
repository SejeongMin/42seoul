/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 15:01:58 by semin             #+#    #+#             */
/*   Updated: 2021/09/21 21:12:21 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define FLAG "-0"
# define TYPE "cspdiuxX%"

typedef struct s_data
{
	int			minus;
	int			zero;
	int			prec;
	int			width;
	int			type;
}				t_data;

void			print_char(char c, t_data *data, int *ret);
void			print_str(char *str, t_data *data, int *ret);
void			print_int(long long num, t_data *data, int *ret);
void			print_ux(unsigned long long num, t_data *data, int *ret);
void			print_p(unsigned long long num, t_data *data, int *ret);

int				ft_parsing(char *str, va_list ap, t_data *data);
char			*ft_find(char *str, char c);

int				ft_toupper(int c);
void			ft_putnbr_base(unsigned long long num, t_data *data);
int				ft_unumlen(unsigned long long num);
int				ft_xnumlen(unsigned long long num);
void			ft_uputnbr(unsigned long long num);

int				ft_printf(const char *format, ...);

#endif
