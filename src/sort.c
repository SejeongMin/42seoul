/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:16:20 by semin             #+#    #+#             */
/*   Updated: 2021/11/03 15:34:15 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int	choose_pivot(t_stack *stack, int range)
{
	int	min;
	int	max;
	int	top;

	min = stack->stack[stack->top];
	max = stack->stack[stack->top];
	top = stack->top;
	while (range--)
	{
		if (stack->stack[top] > max)
			max = stack->stack[top];
		if (stack->stack[top] < min)
			min = stack->stack[top];
		top--;
	}
	return ((min + max) / 2);

	// int	chunk[range];
	// int	top;
	// int	i;
	// int	j;
	// int	tmp;

	// top = stack->top;
	// while (--range >= 0)
	// {
	// 	chunk[range] = stack->stack[top];
	// 	top--;
	// }
	// i = 0;
}

int	a_division(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	count_rotate;
	int	count_push;

	// pivot = a->stack[a->top - (range / 2)];
	pivot = choose_pivot(a, range);
	count_rotate = 0;
	count_push = 0;
	while (range--)
	{
		if (a->stack[a->top] > pivot)
		{
			ft_rotate(a);
			write(1, "ra\n", 3);
			count_rotate++;
		}
		else
		{
			ft_push(b, a);
			write(1, "pb\n", 3);
			// printing(a, b);
			count_push++;
		}
	}
	while (count_rotate--)
	{
		ft_rev_rotate(a);
		write(1, "rra\n", 4);
	}
	return (count_push);
}

int	b_division(t_stack *a, t_stack *b, int range)
{
	int	pivot;
	int	count_rotate;
	int	count_push;

	pivot = choose_pivot(b, range);
	count_rotate = 0;
	count_push = 0;
	while (range--)
	{
		if (b->stack[b->top] < pivot)
		{
			ft_rotate(b);
			write(1, "rb\n", 3);
			count_rotate++;
		}
		else
		{
			ft_push(a, b);
			write(1, "pa\n", 3);
			count_push++;
		}
	}
	while (count_rotate--)
	{
		ft_rev_rotate(b);
		write(1, "rrb\n", 4);
	}
	return (count_push);
}

void	repeat_push(t_stack *s1, t_stack *s2, int range)
{
	while (range--)
	{
		ft_push(s1, s2);
		write(1, "pa\n", 3);
	}
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
	if (range <= 3)
	{
		repeat_push(a, b, range);
		ft_small_range(a, range);
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
	if (a->top == 2)
	{
		ft_three_argument(a);
		return ;
	}
	else if (range <= 3)
	{
		ft_small_range(a, range);
		return ;
	}
	count_push = a_division(a, b, range);
	count_rotate = range - count_push;
	A_to_B(a, b, count_rotate);
	B_to_A(a, b, count_push);
}
