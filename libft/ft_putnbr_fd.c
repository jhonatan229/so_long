/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestevam < jestevam@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:26:00 by jestevam          #+#    #+#             */
/*   Updated: 2021/06/02 15:40:39 by jestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

//transfom the number negative in positive number 
int	ft_to_positive(int nb, int fd)
{
	write(fd, "-", 1);
	if (nb == -2147483648)
	{
		write(fd, "2", 1);
		nb = -147483648;
	}
	return (nb - nb - nb);
}

//pass a number to output 'fd' by 'write'
void	ft_putnbr_fd(int nb, int fd)
{
	char	number;

	if (nb == 2147483647)
	{
		write(fd, "2", 1);
		nb = 147483647;
	}
	if (nb < 0)
		nb = ft_to_positive(nb, fd);
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
		number = (nb % 10) + '0';
		write(fd, &number, 1);
	}
	else
	{
		number = nb + '0';
		write(fd, &number, 1);
	}
}
