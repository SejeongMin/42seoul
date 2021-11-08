/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:16:20 by semin             #+#    #+#             */
/*   Updated: 2021/11/09 02:51:11 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	choose_pivot(t_stack *stack, int range)
{
	int	chunk[range];
	int	tmp_range;
	int	i;
	int	min;
	int	tmp;

	i = stack->top;
	tmp_range = range;
	while (--tmp_range >= 0)
	{
		chunk[tmp_range] = stack->stack[i];
		i--;
	}
	tmp_range = range;
	while (--tmp_range >= 0)
	{
		i = tmp_range - 1;
		min = tmp_range;
		while (i >= 0)
		{
			if (chunk[i] < chunk[min])
				min = i;
			i--;
		}
		tmp = chunk[tmp_range];
		chunk[tmp_range] = chunk[min];
		chunk[min] = tmp;
	}
	return (chunk[(range / 2) + (range % 2)]);
}

int	a_division(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	count_rotate;
	int	count_push;
	int	tmp_range;

	pivot = choose_pivot(a, range);
	count_rotate = 0;
	count_push = 0;
	tmp_range = range;
	while (tmp_range-- && count_push < (range / 2))
	{
		if (a->stack[a->top] > pivot)
		{
			ft_rotate(a);
			count_rotate++;
		}
		else
		{
			ft_push(b, a);
			count_push++;
		}
	}
	while (a->top != (range - count_push - 1) && count_rotate--)
		ft_rev_rotate(a);
	return (count_push);
}

int	b_division(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	count_rotate;
	int	count_push;
	int	tmp_range;

	pivot = choose_pivot(b, range);
	count_rotate = 0;
	count_push = 0;
	tmp_range = range;
	while (tmp_range-- && count_push <= ((range / 2) + (range % 2)))
	{
		if (b->stack[b->top] < pivot)
		{
			ft_rotate(b);
			count_rotate++;
		}
		else
		{
			ft_push(a, b);
			count_push++;
		}
	}
	while (b->top != (range - count_push - 1) && count_rotate--)
		ft_rev_rotate(b);
	return (count_push);
}

void	repeat_push(t_stack *s1, t_stack *s2, int range)
{
	while (range--)
		ft_push(s1, s2);
}

void	B_to_A(t_stack *a, t_stack *b, int range)
{
	int	count_push;
	int	count_rotate;

	if (is_sorted_b(b, range))
	{
		repeat_push(a, b, range);
		return;
	}
	if (range <= 5)
	{
		b_five_arg(a, b, range);
		return ;
	}
	count_push = b_division(a, b, range);
	count_rotate = range - count_push;
	A_to_B(a, b, count_push);
	B_to_A(a, b, count_rotate);
}

void	A_to_B(t_stack *a, t_stack *b, int range)
{
	int	count_push;
	int	count_rotate;

	if (is_sorted_a(a, range))
		return ;
	if (range <= 5)
	{
		a_five_arg(a, b, range);
		return ;
	}
	count_push = a_division(a, b, range);
	count_rotate = range - count_push;
	A_to_B(a, b, count_rotate);
	B_to_A(a, b, count_push);
}
