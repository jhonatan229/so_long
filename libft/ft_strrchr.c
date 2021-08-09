/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:14:48 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/18 15:14:48 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return a pointer to the last occurrence of c in my string s
//return null if not found any occurrence of c
char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = ft_strlen(s);
	while (count >= 0)
	{
		if (s[count] == (char)c)
			return ((char *)s + count);
		count--;
	}
	return (NULL);
}
