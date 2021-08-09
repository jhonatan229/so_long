/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 13:38:48 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 15:47:51 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// take to the string s in the position count, a string until found the char c
static char	*getstr(const char *s, int *count, char c)
{
	char	*rslt;
	int		prslt;
	int		lenstr;

	// creates a variable lenstr, they get the value of count
	lenstr = *count;
	prslt = 0;
	//stay on loop until my s in position lenstr is diferent of char c and \0
	//if true, add one on my lenstr 
	while (s[lenstr] != c && s[lenstr] != 0)
		lenstr++;
	// my lenstr gets the diference of lenstr end my count
	//lenstr now is my length of my string found
	lenstr = lenstr - *count;
	//create a string rslt  with malloc, allocating lenstr + 1 (space of \0) bytes
	rslt = malloc(lenstr + 1);
	// stay in loop if my prslt is smaller than lenstr
	//this loop copy my string found to my rslt
	while (prslt < lenstr)
	{
		rslt[prslt] = s[*count];
		*count += 1;
		prslt++;
	}
	//decrement one of my count and add in the end of my string, \0
	*count -= 1;
	rslt[prslt] = 0;
	return (rslt);
}

//count the quantity of strings separeted by char c
static int	countc(char const *s, char c)
{
	int		count;

	count = 1;
	// percour all my string s
	while (*s != 0)
	{
		// if my s in position is equal c, add more one in my count
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}
// skips the amount of c and return when the pointer s is diferent of c
static void	verifyc(const char *s, int *count, char c)
{
	while (s[*count] != 0 && s[*count] == c)
		*count += 1;
}

//creates a list of strings taking the string s and separete them in substrings with the char c as delimiter 
char	**ft_split(char const *s, char c)
{
	int		count;
	int		n;
	char	**pp;

	// allocates size of pointer with the countc function + 1(space of null)
	pp = ft_calloc((countc(s, c) + 1), sizeof(char *));
	n = 1;
	count = 0;
	//skip the spaces in s that contains char c
	verifyc(s, &count, c);
	//if my s on position count is diferent of \0, 
	//means that have something to write in pp
	if (s[count] != 0)
		pp[0] = getstr(s, &count, c);
	// stay in while until my s ends
	while (s[count++] != 0)
	{
		//if my s on position count is diferent of \0, 
		//means that have something to write in pp
		if (s[count] == c)
		{
			verifyc(s, &count, c);
			if (s[count] != 0)
				pp[n] = getstr(s, &count, c);
			n++;
		}
		//verify if my s ends, if true, skip the last call of my while
		if (s[count] == 0)
			break ;
	}
	return (pp);
}
