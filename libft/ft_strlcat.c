/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:33:57 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/18 13:33:57 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//concatenation the 'size' bytes of my src to my dst
//return the len of dst plus the src that can be concatenation
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			counter;
	size_t			pnt;

	counter = 0;
	pnt = 0;
	//this while count the len of my dest until my count is equal to size or my dest end
	while (dst[counter] != 0 && counter < size)
		counter++;
	//verify with counter + point + 1(space of my \0) if have space enough to concatenate one or more character
	//if true, copy my src in space pnt to my dst in space counter(len of my dest) plus pnt
	while ((counter + pnt + 1) < size && src[pnt] != 0)
	{
		dst[counter + pnt] = src[pnt];
		pnt++;
	}
	//this if verify if my counter is equal to 'size'
	//if not true, allocate, in end of my string, the \0
	if (counter < size)
		dst[counter + pnt] = '\0';
	//return the len of dst plus the src that can be concatenation
	return (counter + ft_strlen(src));
}

