/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:01:13 by semin             #+#    #+#             */
/*   Updated: 2021/09/23 16:38:49 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi(char *s)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		ret = ret * 10 + (*s - '0');
		s++;
	}
	return (ret);
}

void	init_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	int	idx;

	idx = 0;
	a->stack = (int *)malloc(sizeof(int) * (ac - 1));
	b->stack = (int *)malloc(sizeof(int) * (ac - 1));
	a->top = -1;
	b->top = -1;
	while (ac > 1)
	{
		a->stack[idx] = av[ac - 1];
		idx++;
		a->top++;		
		ac--;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a, &b, ac, av);
}
