/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:38:13 by semin             #+#    #+#             */
/*   Updated: 2021/11/04 17:59:08 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *s)
{
	int	tmp;

	tmp = s->stack[s->top];
	s->stack[s->top] = s->stack[s->top - 1];
	s->stack[s->top - 1] = tmp;
	write(1, "s", 1);
	write(1, &s->stack_name, 1);
	write(1, "\n", 1);
}

void	ft_push(t_stack *s1, t_stack *s2)
{
	(s1->top)++;
	s1->stack[s1->top] = s2->stack[s2->top];
	(s2->top)--;
	write(1, "p", 1);
	write(1, &s1->stack_name, 1);
	write(1, "\n", 1);
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
	write(1, "r", 1);
	write(1, &s->stack_name, 1);
	write(1, "\n", 1);
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
	write(1, "rr", 2);
	write(1, &s->stack_name, 1);
	write(1, "\n", 1);
}
