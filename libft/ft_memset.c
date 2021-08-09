/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:10:59 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:10:59 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//population the first n bytes of string ptr with char x
void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t			counter;
	unsigned char	*p;

	//create a pointer p gets ptr, 
	//to be able to manipulates this two strings
	p = (unsigned char *)ptr;
	counter = 0;
	//stay on loop until my counter is equal n
	while (counter < n)
	{
		*p = (unsigned char) x;
		p++;
		counter++;
	}
	return (ptr);
}
