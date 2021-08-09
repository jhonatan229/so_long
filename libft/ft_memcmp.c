/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:42:48 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:42:48 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compare the n firsts bytes of memory of my s1, and s2
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	//create ps1 to s1 and ps2 to my s2 with unsigned char type 
	//to be able to manipulates this two strings
	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	//stay on my loop until my n is diferent of 0
	while (n-- > 0)
	{
		//if my char in my position ps1 is bigger than my char in my position ps2, return 1
		if (*ps1 > *ps2)
			return (*ps1 - *ps2);
		//if my char in my position ps2 is bigger than my char in my position ps1, return -1
		if (*ps2 > *ps1)
			return (*ps1 - *ps2);
		ps2++;
		ps1++;
	}
	// if none diference is found, return 0
	return (0);
}
