/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:57:31 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/18 15:57:31 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//return a number diferent of 0 if my c is alphabetic
int	ft_isalpha(int c)
{
	if ((char)c >= 'a' && (char)c <= 'z')
		return (2);
	if ((char)c >= 'A' && (char)c <= 'Z')
		return (2);
	return (0);
}
