/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:56:57 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:56:58 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				count;
	unsigned char		*pointer_src;
	unsigned char		*dest_pointer;

	if (!dst && !src)
		return (dst);
	count = 0;
	pointer_src = (unsigned char*)src;
	dest_pointer = (unsigned char*)dst;
	while (count < n)
	{
		dest_pointer[count] = pointer_src[count];
		count++;
	}
	return (dst);
}
