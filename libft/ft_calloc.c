/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:45:05 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/27 12:29:14 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//give me nmeb * size spaces in memory, put \0 in each space of memory
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rslt;
	int		sizemax;

	sizemax = nmemb * size;
	//verify if the result of multiplication give me 0, if true, function return is null
	if (sizemax == 0)
		return (NULL);
	rslt = malloc(sizemax);
	//verify if the malloc works
	if (rslt == NULL)
		return (NULL);
	//call my function ft_bzero to put \0 in each space
	ft_bzero(rslt, sizemax);
	return (rslt);
}
