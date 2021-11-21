/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:16:37 by semin             #+#    #+#             */
/*   Updated: 2021/11/13 23:10:44 by semin            ###   ########.fr       */
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
		if (a->stack[cur] > a->stack[cur - 1])
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

int	ft_atoi(char *s, t_stack *a, t_stack *b)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	if (s[0] == '-' || s[0] == '+')
	{
		if (s[0] == '-')
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
			ft_error(a, b);
	}
	if (ret >= 2147483648 || ret <= -2147483649)
		ft_error(a, b);
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

void	init_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	int	idx;

	idx = 0;
	a->stack = (int *)malloc(sizeof(int) * (ac - 1));
	b->stack = (int *)malloc(sizeof(int) * (ac - 1));
	a->stack_name = 'a';
	b->stack_name = 'b';
	a->top = -1;
	b->top = -1;
	while (ac > 1)
	{
		a->stack[idx] = ft_atoi(av[ac - 1], a, b);
		if (is_dup(a->stack, idx) < 0)
			ft_error(a, b);
		idx++;
		a->top++;
		ac--;
	}
}
