/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:38:24 by semin             #+#    #+#             */
/*   Updated: 2021/11/13 20:38:47 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_dup2(t_stack *a, t_stack *b, int idx, int num)
{
	int	i;

	i = a->top;
	a->stack[idx] = num;
	while (i > idx)
	{
		if (a->stack[idx] == a->stack[i])
			ft_error(a, b);
		i--;
	}
}

static void	ft_split(t_stack *a, t_stack *b, char *s)
{
	char	*tmp;
	int		top;
	int		num;

	a->top = wdcount(s) - 1;
	top = a->top;
	while (*s)
	{
		if (*s != ' ')
		{
			tmp = (char *)s;
			num = 0;
			while (*s != ' ' && *s)
			{
				if (*s >= '0' && *s <= '9')
					num = num * 10 + (*(s++) - '0');
				else
					ft_error(a, b);
			}
			is_dup2(a, b, top, num);
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

static void	init_stack(t_stack *a, t_stack *b, int ac, char **av)
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
