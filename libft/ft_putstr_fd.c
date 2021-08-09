/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:13:23 by jestevam          #+#    #+#             */
/*   Updated: 2021/05/27 15:03:04 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//print the string in output fd
void	ft_putstr_fd(char *s, int fd)
{
	while (*s != 0)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
