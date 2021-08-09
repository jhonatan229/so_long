/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:05:57 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 13:25:57 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//add a new t_list in end of my list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = ft_lstlast(*lst);
	if (aux != 0)
		aux->next = new;
	else
		*lst = new;
}
