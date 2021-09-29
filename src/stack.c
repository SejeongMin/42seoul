/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:13:25 by semin             #+#    #+#             */
/*   Updated: 2021/09/23 16:38:51 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *s)
{
	int	tmp;

	tmp = s->stack[s->top];
	s->stack[s->top] = s->stack[s->top - 1];
	s->stack[s->top - 1] = tmp;
}

void	ft_push(t_stack *s1, t_stack *s2)
{
	s1->top++;
	s1->stack[s1->top] = s2->stack[s2->top];
	s2->top--;
}

void	ft_rotate(t_stack *s)
{
	int	tmp;
	int	idx;

	tmp = s->stack[s->top];
	idx = s->top;
	while (idx >= 1)
	{
		s->stack[idx] = s->stack[idx - 1];
		idx--;
	}
	s->stack[0] = tmp;
}

void	ft_rev_rotate(t_stack *s)
{
	int	tmp;
	int	idx;

	tmp = s->stack[0];
	idx = 0;
	while (idx < s->top)
	{
		s->stack[idx] = s->stack[idx + 1];
		idx++;
	}
	s->stack[s->top] = tmp;
}
