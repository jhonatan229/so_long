/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:53:15 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/18 17:53:15 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compare the first n bytes of two strings (s1, s2)
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	//stay on loop until my n is bigger than 0, after this, decrement the n
	while (n--)
	{
		//verify if my pointer ps1 is diferent of pointer ps2
		//if true, return the difference between ps1 and ps2
		if (*ps1 != *ps2)
			return (*ps1 - *ps2);
		//return 0 if any of my strings get to the end
		if (*ps1 == '\0' || *ps2 == '\0')
			return (0);
		//pass the pointer of ps1, ps2 to the next position
		ps1++;
		ps2++;
	}
	//if there is no difference, return 0
	return (0);
}
