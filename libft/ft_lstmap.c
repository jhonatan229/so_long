/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:39:50 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 13:35:08 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// create a new list copy the list 'lst' plus the function f
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	node = ft_lstnew((*f)(lst->content));
	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	list = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew((*f)(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		node = node->next;
		lst = lst->next;
	}
	return (list);
}
