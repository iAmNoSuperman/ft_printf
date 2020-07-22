/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:59:53 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:59:54 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_lil;

	i_big = 0;
	if (*little == '\0' || *big == '\0')
	{
		if (*little == '\0')
			return ((char*)big);
		return (NULL);
	}
	while (len != 0 && i_big <= len && big[i_big] != '\0')
	{
		i_lil = 0;
		while (big[i_big + i_lil] == little[i_lil] && little[i_lil] != '\0')
		{
			i_lil++;
			if (i_big + i_lil <= len && little[i_lil] == '\0')
				return ((char*)&big[i_big]);
		}
		i_big++;
	}
	return (NULL);
}
