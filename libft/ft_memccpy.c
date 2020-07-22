/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:56:34 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:56:35 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*pointer_src;
	unsigned char	*dest_pointer;

	count = 0;
	pointer_src = (unsigned char*)src;
	dest_pointer = (unsigned char*)dst;
	while (count < n)
	{
		dest_pointer[count] = pointer_src[count];
		if (pointer_src[count] == (unsigned char)c)
			return (dst + count + 1);
		count++;
	}
	return (NULL);
}
