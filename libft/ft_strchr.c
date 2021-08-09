/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:00:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/18 15:00:46 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// find the first ocorrence of char c, and return a pointer to next position of my string after int c
char	*ft_strchr(const char *s, int c)
{
	int	count;

	count = 0;
	//stay on loop until my s end
	while (s[count] != 0)
	{
		//if my position count in s is equal c, return a pointer to the next position
		if (s[count] == (char)c)
			return ((char *)s + count);
		count++;
	}
	//if my c is equal to end of string(\0), return a pointer to this space
	if (s[count] == (char)c)
		return ((char *)s + count);
	return (NULL);
}
