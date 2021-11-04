/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:38:24 by semin             #+#    #+#             */
/*   Updated: 2021/11/04 17:51:29 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	long long	ret;
	int	sign;

	ret = 0;
	sign = 1;
	if (s[0] == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			ret = ret * 10 + (*s - '0');
			s++;
		}
		else
			ft_error();
	}
	if (ret >= 2147483648 || ret <= -2147483649)
		ft_error();
	return ((int)ret * sign);
}

int	is_dup(int *stack, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (stack[idx] == stack[i])
			return (-1);
		i++;
	}
	return (1);
}

int	init_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	int	idx;

	idx = 0;
	a->stack = (int *)malloc(sizeof(int) * (ac - 1));
	b->stack = (int *)malloc(sizeof(int) * (ac - 1));
	a->stack_name = 'a';
	b->stack_name = 'b';
	a->top = -1;
	b->top = -1;
	while (ac > 1)
	{
		a->stack[idx] = ft_atoi(av[ac - 1]);
		if (is_dup(a->stack, idx) < 0)
			ft_error();
		idx++;
		a->top++;
		ac--;
	}
	return (1);
}

int	ft_error()
{
	write(1, "Error\n", 6);
	//free
	exit(1);
}

#include <stdio.h>

void printing(t_stack *a, t_stack *b)
{
	int atop = a->top;
	(void)b;
	// int btop = b->top;
	while (atop >= 0){
		printf("%d", a->stack[atop]);
		atop--;
	}
	// while (btop >= 0){
	// 	printf("%d ", b->stack[btop]);
	// 	btop--;
	// }
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1 || ac == 2)
		return (1);
	if (init_stack(&a, &b, ac, av) < 0)
		ft_error();
	A_to_B(&a, &b, ac - 1);
	// printing(&a, &b);
}
