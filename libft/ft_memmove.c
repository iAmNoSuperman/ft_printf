/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:57:06 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:57:07 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*new_src;
	unsigned char	*new_dst;

	count = 0;
	new_src = (unsigned char*)src;
	new_dst = (unsigned char*)dst;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
		while (n-- > 0)
			new_dst[n] = new_src[n];
	else
		while (count < n)
		{
			new_dst[count] = new_src[count];
			count++;
		}
	return (dst);
}
