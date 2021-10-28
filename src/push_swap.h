/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <semin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:13:51 by semin             #+#    #+#             */
/*   Updated: 2021/10/28 16:57:48 by semin            ###   ########.fr       */
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

void	ft_small_range(t_stack *stack, int range);

#endif

