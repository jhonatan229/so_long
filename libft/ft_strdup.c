/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:38:30 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 15:48:54 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//create a copy of my string s with malloc;
char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*rslt;

	size = ft_strlen(s);
	rslt = ft_calloc(size + 1, sizeof(char));
	if (rslt == NULL)
		return (NULL);
	ft_memcpy(rslt, (unsigned char *)s, size);
	return (rslt);
}
