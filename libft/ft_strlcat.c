/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:59:02 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:59:03 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		src_len;
	size_t		index;

	dst_len = 0;
	src_len = 0;
	index = 0;
	while (dst_len < size && *(dst + dst_len))
		dst_len++;
	while (*(src + index))
		index++;
	if (dst_len == size)
		return (dst_len + index);
	index = dst_len;
	while (dst_len < size - 1 && *(src + src_len))
	{
		*(dst + dst_len) = *(src + src_len);
		src_len++;
		dst_len++;
	}
	*(dst + dst_len) = '\0';
	while (*(src + src_len))
		src_len++;
	return (index + src_len);
}
