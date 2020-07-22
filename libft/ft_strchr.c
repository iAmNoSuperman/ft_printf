/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:58:29 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:58:30 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		count;
	char	find;
	char	*ptr;

	ptr = (char*)s;
	find = (char)c;
	count = 0;
	while (*(ptr + count) != '\0')
	{
		if (*(ptr + count) == find)
		{
			ptr = ptr + count;
			return (ptr);
		}
		count++;
	}
	if (!(*(ptr + count)) && find != '\0')
		return (NULL);
	if (find == '\0')
		ptr = ptr + count;
	return (ptr);
}
