/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:10:19 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:10:19 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copy n bytes 'numBytes' from 'from' to 'to', stop after if char c is found
void	*ft_memccpy(void *to, const void *from, int c, size_t numBytes)
{
	size_t	count;
	char	*pto;
	char	*pfrom;

	//create two variables (char*) to 'to' 'from'
	pto = (char *)to;
	pfrom = (char *)from;
	count = 0;
	//my while stay in loop until my count is equal numBytes
	while (count < numBytes)
	{
		pto[count] = pfrom[count];
		//aways verify if my position of pfrom is equal my char c
		if (pfrom[count] == (char)c)
			//if true, return a pointer 'to' in position count + 1 (the next char)
			return (to + ++count);
		count++;
	}
	//if my c is not found, return null
	return (NULL);
}
