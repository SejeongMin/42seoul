/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:59:33 by semin             #+#    #+#             */
/*   Updated: 2021/05/15 15:38:46 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lst_free(t_list *cur, void (*del)(void *))
{
	if (cur)
	{
		del(cur->content);
		lst_free(cur->next, del);
		free(cur);
	}
}

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	lst_free(*lst, del);
	*lst = NULL;
}
