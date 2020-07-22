/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:59:11 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:59:12 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned char	*ptr_src;
	size_t			len;

	ptr_src = (unsigned char*)src;
	len = 0;
	if (!dst || !src)
		return (len);
	if (size != 0)
	{
		while (len < size - 1 && *ptr_src)
		{
			*dst = *ptr_src;
			dst++;
			ptr_src++;
			len++;
		}
		*dst = '\0';
	}
	len = 0;
	while (src[len])
	{
		len++;
	}
	return (len);
}
