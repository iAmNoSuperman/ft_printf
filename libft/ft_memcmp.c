/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <vtweek@student.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 10:27:30 by student           #+#    #+#             */
/*   Updated: 2020/05/22 16:02:54 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*new_s1;
	unsigned char	*new_s2;
	size_t			ind;
	int				result;

	new_s1 = (unsigned char*)s1;
	new_s2 = (unsigned char*)s2;
	ind = 0;
	result = 0;
	if (n > 0)
	{
		while (ind < n - 1 && new_s2[ind] == new_s1[ind])
			ind++;
		result = new_s1[ind] - new_s2[ind];
	}
	return (result);
}
