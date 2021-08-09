/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:04:55 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 16:23:23 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//have a function f and a sitring s as parameter 
//pass per my string s and in each loop, give to function f the position to character on string and a character
//return a pointer to beginning of my string s
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*rslt;

	count = 0;
	rslt = malloc(ft_strlen(s) + 1);
	if (rslt == NULL)
		return (NULL);
	while (s[count] != 0)
	{
		rslt[count] = f(count, s[count]);
		count++;
	}
	rslt[count] = 0;
	return (rslt);
}