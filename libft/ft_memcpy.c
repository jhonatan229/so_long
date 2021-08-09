/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:10:36 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:10:36 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//copy n bytes from my 'from' to my 'to'
void	*ft_memcpy(void *to, const void *from, size_t numBytes)
{
	unsigned char	*pto;
	unsigned char	*pfrom;

	//create pto to 'to' and pfrom to my from with unsigned char type 
	//to be able to manipulates this two strings
	pto = (unsigned char *)to;
	pfrom = (unsigned char *)from;
	if (to == NULL && from == NULL)
		return (NULL);
	////stay on my loop until my numBytes is diferent of 0
	while (numBytes--)
	{
		*pto = *pfrom;
		pfrom++;
		pto++;
	}
	return (to);
}
