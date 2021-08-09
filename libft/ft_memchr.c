/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:09:41 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/17 22:09:41 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// search in string s,on the firsts n bytes, the first charactere that is equals to char c
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	unsigned char	*findc;

	// creates a pointer char, pointing to my s, and initialize findc as null
	ps = (unsigned char *) s;
	findc = NULL;
	//stay on my while if my n is different of 0, already decrement n
	while (n--)
	{
		//verify if my position ps is equal to char c, if true, my variable findc get the pointer ps
		//and break the loop
		if (*ps == (unsigned char)c)
		{
			findc = ps;
			break ;
		}
		ps++;
	}
	return (findc);
}
