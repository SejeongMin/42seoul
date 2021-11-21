/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:38:24 by semin             #+#    #+#             */
/*   Updated: 2021/11/13 23:11:24 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_dup2(t_stack *a, t_stack *b, int idx, long long num)
{
	int	i;

	if (num >= 2147483648 || num <= -2147483649)
		ft_error(a, b);
	i = a->top;
	a->stack[idx] = num;
	while (i > idx)
	{
		if (a->stack[idx] == a->stack[i])
			ft_error(a, b);
		i--;
	}
}

static int	split_atoi(t_stack *a, t_stack *b, char *s, int top)
{
	long long	num;
	int			sign;
	char		*tmp;

	sign = 1;
	tmp = s;
	if (*s != ' ')
	{
		if (*s == '-' || *s == '+')
		{
			if (*s == '-')
				sign = -1;
			s++;
		}
		num = 0;
		while (*s != ' ' && *s)
		{
			if (*s >= '0' && *s <= '9')
				num = num * 10 + (*(s++) - '0');
			else
				ft_error(a, b);
		}
		is_dup2(a, b, top, (num * sign));
	}
	return (s - tmp);
}

static void	ft_split(t_stack *a, t_stack *b, char *s)
{
	int	top;

	a->top = wdcount(s) - 1;
	top = a->top;
	while (*s)
	{
		if (*s != ' ')
		{
			s += split_atoi(a, b, s, top);
			top--;
		}
		if (*s)
			s++;
	}
}

static void	one_argument(t_stack *a, t_stack *b, char *s)
{
	a->stack = (int *)malloc(sizeof(int) * wdcount(s));
	b->stack = (int *)malloc(sizeof(int) * wdcount(s));
	a->stack_name = 'a';
	b->stack_name = 'b';
	b->top = -1;
	ft_split(a, b, s);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		one_argument(&a, &b, av[1]);
		a_to_b(&a, &b, wdcount(av[1]));
	}
	else
	{
		init_stack(&a, &b, ac, av);
		a_to_b(&a, &b, ac - 1);
	}
}
