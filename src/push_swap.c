/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:38:24 by semin             #+#    #+#             */
/*   Updated: 2021/10/11 20:38:26 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	long long	ret;

	ret = 0;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
		{
			ret = ret * 10 + (*s - '0');
			s++;
		}
		else
			return (-1);
	}
	if (ret >= 2147483648 || ret <= -2147483649)
		return (-1);
	return ((int)ret);
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
	a->top = -1;
	b->top = -1;
	while (ac > 1)
	{
		if (ft_atoi(av[ac - 1]) >= 0)
			a->stack[idx] = ft_atoi(av[ac - 1]);
		else
			return (-1);
		if (is_dup(a->stack, idx) < 0)
			return (-1);
		idx++;
		a->top++;
		ac--;
	}
}

int	error()
{
	//ft_printf("Error\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1 || ac == 2)
		return (1);
	if (init_stack(&a, &b, ac, av) < 0)
		return (error());
}
