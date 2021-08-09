/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:11:22 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 13:20:49 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return a number diferent of 0 if my c is alphabet or numeric 
int	ft_isalnum(int c)
{
	if ((char)c >= 'a' && (char)c <= 'z')
		return (8);
	if ((char)c >= 'A' && (char)c <= 'Z')
		return (8);
	if ((char)c >= '0' && (char)c <= '9')
		return (8);
	return (0);
}
