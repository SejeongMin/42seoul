/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:16:20 by semin             #+#    #+#             */
/*   Updated: 2021/11/01 18:28:18 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_division(t_stack *s1, t_stack *s2, int range)
{
	int	pivot;
	int	count_rotate;
	int	count_push;

	pivot = s1->stack[s1->top];
	count_rotate = 0;
	count_push = 0;
	while (range--)
	{
		if (s1->stack[s1->top] > pivot)
		{
			ft_rotate(s1);
			write(1, "ra\n", 3);
			count_rotate++;
		}
		else
		{
			ft_push(s2, s1);
			write(1, "pb\n", 3);
			count_push++;
		}
	}
	while (count_rotate--)
	{
		ft_rev_rotate(s1);
		write(1, "rra\n", 4);
	}
	return (count_push);
}

int	b_division(t_stack *s1, t_stack *s2, int range)
{
	int	pivot;
	int	count_rotate;
	int	count_push;

	pivot = s1->stack[s1->top];
	count_rotate = 0;
	count_push = 0;
	while (range--)
	{
		if (s1->stack[s1->top] < pivot)
		{
			ft_rotate(s1);
			write(1, "rb\n", 3);
			count_rotate++;
		}
		else
		{
			ft_push(s2, s1);
			write(1, "pa\n", 3);
			count_push++;
		}
	}
	while (count_rotate--)
	{
		ft_rev_rotate(s1);
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
	count_push = b_division(b, a, range);
	count_rotate = range - count_push;
	A_to_B(a, b, count_push);
	B_to_A(a, b, count_rotate);
}

void	A_to_B(t_stack *a, t_stack *b, int range)
{
	int	return_value[2];
	int	count_push;
	int	count_rotate;

	if (is_sorted_a(a, range))
		return ;
	if (range <= 3)
	{
		ft_small_range(a, range);
		return ;
	}
	count_push = a_division(a, b, range);
	count_rotate = range - count_push;
	A_to_B(a, b, count_rotate);
	B_to_A(a, b, count_push);
}
