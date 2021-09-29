#include "push_swap.h"

void	partition_a(t_stack *a, t_stack *b, int bottom)
{
	int	pivot;
	int	idx;
	int	count;

	pivot = a->stack[0];
	count = a->top - bottom;
	idx = a->top;
	while (count--)
	{
		if (a->stack[idx] < pivot)
		{
			ft_push(b, a);
			write(1, "pb\n", 3);
			idx--;
		}
		else
		{
			ft_rotate(a);
			write(1, "ra\n", 3);
		}
	}
}

void	init_partition(t_stack *a, t_stack *b, int bottom)
{	
}
