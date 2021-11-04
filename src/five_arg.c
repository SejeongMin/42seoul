/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:48:09 by semin             #+#    #+#             */
/*   Updated: 2021/11/04 17:55:17 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion1(t_stack *a, t_stack *b, int range)
{
	int	count;
	int	idx;
	int	tmp;

	idx = a->top;
	tmp = range;
	while (tmp--)
	{
		if (a->stack[idx] < b->stack[b->top])
			idx--;
		else
			break;
	}
	count = a->top - idx;
	if (count == range)
	{
		ft_push(a, b);
		ft_rotate(a);
	}
	else if (count <= (range / 2))
	{
		tmp = count;
		while(tmp--)
			ft_rotate(a);
		ft_push(a, b);
		while (a->top != (count - 1) && count--)
			ft_rev_rotate(a);
	}
	else
	{
		ft_rev_rotate(a);
		ft_push(a, b);
		ft_rotate(a);
		ft_rotate(a);
	}
}

void	ft_insertion2(t_stack *a, t_stack *b, int range)
{
	int	count;
	int	idx;
	int	tmp;

	idx = a->top;
	tmp = range;
	while (tmp--)
	{
		if (a->stack[idx] < b->stack[b->top])
			idx--;
		else
			break;
	}
	count = a->top - idx;
	tmp = count;
	while(tmp--)
		ft_rotate(a);
	ft_push(a, b);
	while (a->top != (count - 1) && count--)
		ft_rev_rotate(a);
}

void	a_five_arg(t_stack *a, t_stack *b, int range)
{
	if (range <= 3)
	{
		ft_small_range(a, range);
		return ;
	}
	ft_push(b, a);
	if (range == 5)
		ft_push(b, a);
	ft_small_range(a, 3);
	if (a->top <= 4)
	{
		ft_insertion1(a, b, 3);
		if (range == 5)
			ft_insertion1(a, b, 4);
	}
	else
	{
		ft_insertion2(a, b, 3);
		if (range == 5)
			ft_insertion2(a, b, 4);
	}
}

void	b_five_arg(t_stack *a, t_stack *b, int range)
{
	if (range <= 3)
	{
		repeat_push(a, b, range);
		ft_small_range(a, range);
		return ;
	}
	repeat_push(a, b, 3);
	ft_small_range(a, 3);
	if (a->top <= 4)
	{
		ft_insertion1(a, b, 3);
		if (range == 5)
			ft_insertion1(a, b, 4);
	}
	else
	{
		ft_insertion2(a, b, 3);
		if (range == 5)
			ft_insertion2(a, b, 4);
	}
}
