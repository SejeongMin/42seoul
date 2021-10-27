/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:38:24 by semin             #+#    #+#             */
/*   Updated: 2021/10/27 11:55:03 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	long long	ret;

	ret = 0;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			ret = ret * 10 + (*s - '0');
			s++;
		}
		else
			return (-1);
	}
	if (ret >= 2147483648 || ret <= -2147483649)
		return (-1);
	return ((int)ret);
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

int	init_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	int	idx;

	idx = 0;
	a->stack = (int *)malloc(sizeof(int) * (ac - 1));
	b->stack = (int *)malloc(sizeof(int) * (ac - 1));
	a->top = -1;
	b->top = -1;
	while (ac > 1)
	{
		if (ft_atoi(av[ac - 1]) >= 0)
			a->stack[idx] = ft_atoi(av[ac - 1]);
		else
			return (-1);
		if (is_dup(a->stack, idx) < 0)
			return (-1);
		idx++;
		a->top++;
		ac--;
	}
	return (1);
}

int	error()
{
	write(1, "Error\n", 6);
	return (0);
}

#include <stdio.h>

void A_to_B(t_stack *a, t_stack *b, int top)
{
	int	count_ra;
	int	count_pb;
	int	pivot;

	if (top == 0)
		return ;
	pivot = a->stack[a->top];
	count_ra = 0;
	count_pb = 0;
	while (top >= 0)
	{
		if (a->stack[top] > pivot)
		{
			ft_rotate(a);
			count_ra++;
		}
		else
		{
			ft_push(b, a);
			count_pb++;
		}
		top--;
	}
	int t = b->top;
	while (t >= 0){
		printf("%d", b->stack[t]);
		t--;
	}
	// 두 개로 나누는것까진 구현함
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1 || ac == 2)
		return (1);
	if (init_stack(&a, &b, ac, av) < 0)
		return (error());
	A_to_B(&a, &b, a.top);
}
