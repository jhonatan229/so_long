/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 01:17:48 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 13:21:11 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return a number diferent of 0 if my c is in ASCII table
int	ft_isascii(int c)
{
	if ((char)c >= 0 && (char)c <= 127)
		return (1);
	return (0);
}
