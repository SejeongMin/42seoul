/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:13:04 by semin             #+#    #+#             */
/*   Updated: 2021/11/03 15:03:48 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    ft_size3(t_stack *stack)
{
	int	*s;
	int	t;

	s = stack->stack;
	t = stack->top;
	if (s[t - 2] > s[t - 1] && s[t - 2] > s[t] && s[t - 1] < s[t])
		ft_swap(stack);
	else if (s[t - 2] < s[t - 1] && s[t - 2] > s[t] && s[t - 1] > s[t])
	{
		ft_rotate(stack);
		write(1, "ra\n", 3);
		ft_swap(stack);
		ft_rev_rotate(stack);
		write(1, "rra\n", 4);
	}
	else if (s[t - 2] < s[t - 1] && s[t - 2] < s[t] && s[t - 1] > s[t])
	{
		ft_rotate(stack);
		write(1, "ra\n", 3);
		ft_swap(stack);
		ft_rev_rotate(stack);
		write(1, "rra\n", 4);
		ft_swap(stack);
	}
	else if (s[t - 2] > s[t - 1] && s[t - 2] < s[t] && s[t - 1] < s[t])
	{
		ft_swap(stack);
		ft_rotate(stack);
		write(1, "ra\n", 3);
		ft_swap(stack);
		ft_rev_rotate(stack);
		write(1, "rra\n", 4);
	}
	else if (s[t - 2] < s[t - 1] && s[t - 2] < s[t] && s[t - 1] < s[t])
	{
		ft_swap(stack);
		ft_rotate(stack);
		write(1, "ra\n", 3);
		ft_swap(stack);
		ft_rev_rotate(stack);
		write(1, "rra\n", 4);
		ft_swap(stack);
	}
}

static void    ft_size2(t_stack *s)
{
	if (s->stack[s->top - 1] < s->stack[s->top])
		ft_swap(s);
}

void	ft_small_range(t_stack *stack, int range)
{
	if (range == 0 || range == 1)
		return ;
	else if (range == 2)
		ft_size2(stack);
	else if (range == 3)
		ft_size3(stack);
}

void	ft_three_argument(t_stack *stack)
{
	int	*s;
	int	t;

	s = stack->stack;
	t = stack->top;
	if (s[t - 2] > s[t - 1] && s[t - 2] > s[t] && s[t - 1] < s[t])
		ft_swap(stack);
	else if (s[t - 2] < s[t - 1] && s[t - 2] > s[t] && s[t - 1] > s[t])
	{
		ft_rotate(stack);
		write(1, "ra\n", 3);
		ft_swap(stack);
		ft_rev_rotate(stack);
		write(1, "rra\n", 4);
	}
	else if (s[t - 2] < s[t - 1] && s[t - 2] < s[t] && s[t - 1] > s[t])
	{
		ft_rotate(stack);
		write(1, "ra\n", 3);
		ft_swap(stack);
		ft_rev_rotate(stack);
		write(1, "rra\n", 4);
		ft_swap(stack);
	}
	else if (s[t - 2] > s[t - 1] && s[t - 2] < s[t] && s[t - 1] < s[t])
	{
		ft_rotate(stack);
		write(1, "ra\n", 3);
	}
	else if (s[t - 2] < s[t - 1] && s[t - 2] < s[t] && s[t - 1] < s[t])
	{
		ft_rotate(stack);
		write(1, "ra\n", 3);
		ft_swap(stack);
	}
}
