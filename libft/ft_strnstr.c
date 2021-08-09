/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:12:00 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/18 16:12:00 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//find the first ocorrence of my string 'needle' in my 'haystack'
//search the only first 'n' characters of my haystack
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	phay;
	size_t	pneed;

	phay = 0;
	//verify if my needle is equals to 0, if true, return a pointer to the beegin of my haystack
	if (*needle == 0)
		return ((char *)haystack);
	//verify if my haystack in position phay is different to \0
	while (haystack[phay] != 0)
	{
		pneed = 0;
		while (haystack[phay + pneed] == needle[pneed] && (phay + pneed) < len)
		{
			//if the next position of my needle is \0, return a pointer of beegin of my string needle in haystack
			if (needle[pneed + 1] == 0)
				return ((char *) haystack + phay);
			pneed++;
		}
		phay++;
	}
	// return null if my needle doesn't found
	return (NULL);
}
