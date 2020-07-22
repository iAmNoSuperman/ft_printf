/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:57:47 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:57:49 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	digit;
	char			number;

	if (n < 0)
	{
		digit = -n;
		write(fd, "-", 1);
	}
	else
		digit = n;
	if (digit >= 10)
		ft_putnbr_fd(digit / 10, fd);
	number = digit % 10 + 48;
	write(fd, &number, 1);
}
