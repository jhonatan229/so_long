/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:28:22 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 13:30:23 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//clean the list of t_list
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	while (*lst)
	{
		aux = *lst;
		del(aux->content);
		*lst = aux->next;
		free(aux);
	}
	*lst = NULL;
}
