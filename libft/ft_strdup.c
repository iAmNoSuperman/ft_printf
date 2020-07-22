/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:58:38 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/28 11:48:08 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*c;
	int		i;

	i = 0;
	while (str[i])
		i++;
	c = (char*)malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
