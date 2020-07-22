/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:00:23 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/28 13:33:38 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	size_t			fact_len;
	char			*result;

	index = 0;
	fact_len = 0;
	if (!s || start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	while (fact_len < len && s[fact_len + start] != '\0')
		fact_len++;
	if (!(result = (char*)malloc(sizeof(char) * (fact_len + 1))))
		return (NULL);
	while (fact_len > 0 && s[start] != '\0')
	{
		result[index] = s[start];
		start++;
		index++;
		fact_len--;
	}
	result[index] = '\0';
	return (result);
}
