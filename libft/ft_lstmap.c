/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 19:27:37 by semin             #+#    #+#             */
/*   Updated: 2021/05/15 14:08:05 by semin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(head = ft_lstnew(f(lst->content))))
		return (NULL);
	tmp = head;
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tmp->next = new;
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
