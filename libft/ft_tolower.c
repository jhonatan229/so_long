/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:08:02 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 17:54:30 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//transform the char 'c' in lowercase if my c is a upper case
//retur c if is not upper case
int	ft_tolower(int c)
{
	if ((char)c >= 'A' && (char)c <= 'Z')
		return (c + 32);
	return (c);
}
