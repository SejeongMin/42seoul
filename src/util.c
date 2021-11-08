/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:16:37 by semin             #+#    #+#             */
/*   Updated: 2021/11/09 02:28:17 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_stack *a, int range)
{
	int	cur;

	if (range == 0 || range == 1)
		return (1);
	cur = a->top;
	while (--range)
	{
		if (a->stack[cur] > a->stack[cur - 1]) //중복검사 여기서 하면 되겠다~
			return (0);
		cur--;
	}
	return (1);
}

int	is_sorted_b(t_stack *b, int range)
{
	int	cur;

	if (range == 0 || range == 1)
		return (1);
	cur = b->top;
	while (--range)
	{
		if (b->stack[cur] < b->stack[cur - 1])
			return (0);
		cur--;
	}
	return (1);
}

int	ft_error()
{
	write(1, "Error\n", 6);
	//free
	exit(1);
}

int	ft_atoi(char *s)
{
	long long	ret;
	int	sign;

	ret = 0;
	sign = 1;
	if (s[0] == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			ret = ret * 10 + (*s - '0');
			s++;
		}
		else
			ft_error();
	}
	if (ret >= 2147483648 || ret <= -2147483649)
		ft_error();
	return ((int)ret * sign);
}

int	is_dup(int *stack, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (stack[idx] == stack[i])
			return (-1);
		i++;
	}
	return (1);
}
