/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:06:38 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/28 14:52:47 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//transform the char 'c' in uppercase if my c is a lower case
//retur c if is not lower case
int	ft_toupper(int c)
{
	if ((unsigned char)c >= 'a' && (unsigned char)c <= 'z')
		return (c - 32);
	return (c);
}
