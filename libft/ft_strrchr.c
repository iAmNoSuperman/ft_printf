/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <vtweek@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 12:38:57 by student           #+#    #+#             */
/*   Updated: 2020/05/18 19:39:51 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = 0;
	while (*s)
	{
		if (*s == c)
			ptr = (char*)s;
		s++;
	}
	if (ptr)
		return (ptr);
	if (c == '\0')
	{
		ptr = (char*)s++;
		return (ptr);
	}
	return (NULL);
}
