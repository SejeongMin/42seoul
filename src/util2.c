/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:48:09 by semin             #+#    #+#             */
/*   Updated: 2021/11/13 22:16:55 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_min(t_stack *s1, t_stack *s2, int range)
{
	int	min;
	int	top;
	int	tmp;

	min = s1->top;
	top = s1->top;
	while (range--)
	{
		if (s1->stack[top] < s1->stack[min])
			min = top;
		top--;
	}
	top = s1->top - min;
	tmp = top;
	while (tmp--)
		ft_rotate(s1);
	ft_push(s2, s1);
	while (s1->top != (top - 1) && top--)
		ft_rev_rotate(s1);
}

void	a_five_arg(t_stack *a, t_stack *b, int range)
{
	if (range <= 3)
		ft_small_range(a, range);
	else if (range == 5)
	{
		a_division(a, b, range);
		ft_small_range(a, 3);
		ft_push(a, b);
		ft_push(a, b);
		ft_size2(a);
	}
	else
	{
		push_min(a, b, range);
		ft_small_range(a, 3);
		ft_push(a, b);
	}
}

void	repeat_push(t_stack *s1, t_stack *s2, int range)
{
	while (range--)
		ft_push(s1, s2);
}

static void	sort_array(int *chunk, int range)
{
	int	tmp;
	int	min;
	int	i;

	while (--range >= 0)
	{
		i = range - 1;
		min = range;
		while (i >= 0)
		{
			if (chunk[i] < chunk[min])
				min = i;
			i--;
		}
		tmp = chunk[range];
		chunk[range] = chunk[min];
		chunk[min] = tmp;
	}
}

int	choose_pivot(t_stack *stack, int range)
{
	int	*chunk;
	int	tmp_range;
	int	i;
	int	ret;

	chunk = (int *)malloc(sizeof(int) * range);
	i = stack->top;
	tmp_range = range;
	while (--tmp_range >= 0)
	{
		chunk[tmp_range] = stack->stack[i];
		i--;
	}
	sort_array(chunk, range);
	ret = chunk[(range / 2) + (range % 2)];
	free(chunk);
	return (ret);
}
