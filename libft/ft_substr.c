/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:08:46 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 17:54:17 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return a new string with n bytes 'len', and starting to copy from my 'start'
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			psub;

	psub = 0;
	sub = ft_calloc(len + 1, sizeof(char));
	if (sub == NULL || s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (sub);
	while (psub < len)
	{
		sub[psub] = s[start];
		start++;
		psub++;
	}
	return (sub);
}