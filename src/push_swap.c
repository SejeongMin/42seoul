/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:38:24 by semin             #+#    #+#             */
/*   Updated: 2021/11/09 03:06:01 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_dup2(t_stack *a, int idx, int num)
{
	int	i;

	i = a->top;
	a->stack[idx] = num;
	while (i > idx)
	{
		if (a->stack[idx] == a->stack[i])
			ft_error();
		i--;
	}
}

static void	ft_split(t_stack *a, char *s)
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
					ft_error();
			}
			is_dup2(a, top, num);
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
	ft_split(a, s);
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
		a->stack[idx] = ft_atoi(av[ac - 1]);
		if (is_dup(a->stack, idx) < 0)
			ft_error();
		idx++;
		a->top++;
		ac--;
	}
}

#include <stdio.h>

void printing(t_stack *a, t_stack *b)
{
	int atop = a->top;
	(void)b;
	// int btop = b->top;
	while (atop >= 0){
		printf("%d ", a->stack[atop]);
		atop--;
	}
	// while (btop >= 0){
	// 	printf("%d ", b->stack[btop]);
	// 	btop--;
	// }
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
		A_to_B(&a, &b, wdcount(av[1]));
	}
	else
	{
		init_stack(&a, &b, ac, av);
		A_to_B(&a, &b, ac - 1);
	}
	// printing(&a, &b);
}
