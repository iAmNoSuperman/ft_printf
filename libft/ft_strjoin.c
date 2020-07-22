/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:58:50 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/28 11:51:08 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		index;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	len = 0;
	while (s1[index])
	{
		new[index] = s1[index];
		index++;
	}
	while (s2[len])
	{
		new[index + len] = s2[len];
		len++;
	}
	new[index + len] = '\0';
	return (new);
}
