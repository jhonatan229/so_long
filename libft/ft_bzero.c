/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:10:07 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:10:07 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// transform, in my string s, n bytes in \0 
void	ft_bzero(void *s, size_t n)
{
	size_t			count;
	unsigned char	*p;

	p = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		*p = 0;
		p++;
		count++;
	}
	return ;
}
