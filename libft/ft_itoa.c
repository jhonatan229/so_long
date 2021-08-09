/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:30:27 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 13:23:24 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//trasform my nb in positive number
int	static	ft_to_positive(int nb, char *rslt, int *count)
{
	//put '-' in my string result and add more one on my count that is on my function ft_itoa
	rslt[0] = '-';
	*count += 1;
	//verify if my nb if a INT MIN, if true, print the place left, 
	//add one on my count, and give a new number to my nb whitout the number print
	if (nb == -2147483648)
	{
		rslt[1] = '2';
		*count += 1;
		nb = -147483648;
	}
	//return my nb positive
	return (nb - nb - nb);
}

//count a quantity of places on my number nb
int static	ft_quantitynum(int nb)
{
	int		count;
	int		pos;

	pos = 0;
	count = 0;
	//if my nb is negative, trasform them in positive
	//add more one on my count because of the '-'
	if (nb < 0)
	{
		pos = nb - nb - nb;
		nb = pos;
		count++;
	}
	// verify if my nb is a INT MIN, if true, return the length of nb 
	//counting my \0 after 8 on the right
	if (nb == -2147483648)
		return (11);
	//verify if my nb have two places, if true, divide this number by 10
	//add more one on my count
	while (nb >= 10)
	{
		nb /= 10;
		count++;
	}
	//return my count + 1 that is my lonely number that dont pass in my last while
	return (count + 1);
}

// transform my int n in a string
char	*ft_itoa(int n)
{
	char	*rslt;
	int		count;
	int		firstpos;

	firstpos = 0;
	//my count get the lenght of my number
	count = ft_quantitynum(n);
	//allocates count + 1(space of \0) space
	rslt = malloc(count + 1);
	if (rslt == NULL)
		return (NULL);
	//allocates the last space of my rslt to \0
	rslt[count] = 0;
	count--;
	// trasform my n in positive if necesary
	if (n < 0)
		n = ft_to_positive(n, rslt, &firstpos);
	//put the number in my rslt, until my count is equal 0
	while (count >= firstpos)
	{
		// the '0' is the number, in ASCII table of numbers 0-9
		rslt[count] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (rslt);
}
