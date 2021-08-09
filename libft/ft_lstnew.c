/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 12:11:31 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 13:35:32 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//create a net item t_list
t_list	*ft_lstnew(void *content)
{
	t_list	*stcr;

	stcr = malloc(sizeof(t_list));
	if (stcr == NULL)
		return (NULL);
	stcr->content = content;
	stcr->next = NULL;
	return (stcr);
}
