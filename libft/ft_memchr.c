/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:56:46 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:56:48 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*pointer;
	unsigned char	simbol;

	count = 0;
	pointer = (unsigned char *)s;
	simbol = (unsigned char)c;
	while (count < n)
	{
		if (pointer[count] == simbol)
		{
			pointer = pointer + count;
			return (pointer);
		}
		count++;
	}
	return (NULL);
}
