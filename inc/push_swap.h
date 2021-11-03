/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:13:51 by semin             #+#    #+#             */
/*   Updated: 2021/11/03 15:01:01 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack{
	int *stack;
	int top;
}   t_stack;

typedef struct s_chunk{
	int	top;
	int	bottom;
}	t_chunk;

# include <stdlib.h>
# include <unistd.h>

void	ft_swap(t_stack *s);
void	ft_push(t_stack *s1, t_stack *s2);
void	ft_rotate(t_stack *s);
void	ft_rev_rotate(t_stack *s);

int		ft_error();

void	ft_small_range(t_stack *stack, int range);
void	ft_three_argument(t_stack *stack);

void	A_to_B(t_stack *a, t_stack *b, int range);

int		is_sorted_a(t_stack *a, int range);
int		is_sorted_b(t_stack *b, int range);

void 	printing(t_stack *a, t_stack *b);

#endif

