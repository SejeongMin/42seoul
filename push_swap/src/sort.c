/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:16:20 by semin             #+#    #+#             */
/*   Updated: 2021/11/13 22:17:08 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	b_to_a(t_stack *a, t_stack *b, int range)
{
	int	count_push;
	int	count_rotate;

	if (is_sorted_b(b, range))
	{
		repeat_push(a, b, range);
		return ;
	}
	if (range <= 3)
	{
		repeat_push(a, b, range);
		ft_small_range(a, range);
		return ;
	}
	count_push = b_division(a, b, range);
	count_rotate = range - count_push;
	a_to_b(a, b, count_push);
	b_to_a(a, b, count_rotate);
}

void	a_to_b(t_stack *a, t_stack *b, int range)
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
	a_to_b(a, b, count_rotate);
	b_to_a(a, b, count_push);
}
