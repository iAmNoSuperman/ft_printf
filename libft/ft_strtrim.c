/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:46:08 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/28 13:35:09 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	size_t	from_end;
	char	*result;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	len = ft_strlen((char*)s1 + start);
	from_end = len + start;
	if (from_end == start)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[from_end]))
		from_end--;
	from_end -= start - 1;
	if (!(result = (char*)malloc(sizeof(char) * (from_end + 1))))
		return (NULL);
	ft_strlcpy(result, s1 + start, from_end + 1);
	return (result);
}
