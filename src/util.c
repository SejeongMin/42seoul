/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:16:37 by semin             #+#    #+#             */
/*   Updated: 2021/11/01 18:24:48 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_stack *a, int range)
{
	int	cur;

	if (range == 0 || range == 1)
		return (1);
	cur = a->top;
	while (--range)
	{
		if (a->stack[cur] > a->stack[cur - 1]) //중복검사 여기서 하면 되겠다~
			return (0);
		cur--;
	}
	return (1);
}

int	is_sorted_b(t_stack *b, int range)
{
	int	cur;

	if (range == 0 || range == 1)
		return (1);
	cur = b->top;
	while (--range)
	{
		if (b->stack[cur] < b->stack[cur - 1])
			return (0);
		cur--;
	}
	return (1);
}
