/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:10:44 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:10:44 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//move the first n bytes from my 'from' to my 'to'
void	*ft_memmove(void *to, const void *from, size_t numBytes)
{
	char	*pto;
	char	*pfrom;

	pto = (char *)to;
	pfrom = (char *)from;
	if (to == NULL && from == NULL)
		return (NULL);
	//verify if my two strings is the same string, if true, return a pointer to the begin of my string to
	if (ft_memcmp(to, from, numBytes) == 0)
		return (to);
	//verify if my len of 'to' is smaller than len 'from'
	//if true, call my memcpy
	if (to < from)
		ft_memcpy(pto, pfrom, numBytes);
	//if not true, copy the n bytes of memory, decrement the 'numBytes' in each loop
	else
		while (numBytes--)
			pto[numBytes] = pfrom[numBytes];
	return (to);
}
