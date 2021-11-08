/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:13:51 by semin             #+#    #+#             */
/*   Updated: 2021/11/09 02:51:21 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack{
	int 	*stack;
	int 	top;
	char	stack_name;
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

int		is_dup(int *stack, int idx);

void	a_five_arg(t_stack *a, t_stack *b, int range);
void	b_five_arg(t_stack *a, t_stack *b, int range);

int		wdcount(char *s);

void	A_to_B(t_stack *a, t_stack *b, int range);

int		is_sorted_a(t_stack *a, int range);
int		is_sorted_b(t_stack *b, int range);

int		a_division(t_stack *a, t_stack *b, int range);
int		b_division(t_stack *a, t_stack *b, int range);

void    ft_size2(t_stack *s);

int		ft_atoi(char *s);

int		choose_pivot(t_stack *stack, int range);

void	repeat_push(t_stack *s1, t_stack *s2, int range);

#endif

