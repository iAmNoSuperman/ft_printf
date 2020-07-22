/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:59:45 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:59:46 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*str1;
	unsigned char	*str2;
	int				result;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	idx = 0;
	result = 0;
	if (n > 0)
	{
		while (idx < n - 1 && str1[idx] != '\0' && str2[idx] == str1[idx])
			idx++;
		result = (unsigned char)s1[idx] - (unsigned char)s2[idx];
	}
	return (result);
}
