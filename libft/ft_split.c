/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:58:13 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:58:16 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ln(const char *str, char c)
{
	int		length;

	length = 0;
	while (*str != c && *str != '\0')
	{
		length++;
		str++;
	}
	return (length);
}

static int		ft_wdc(const char *str, char c)
{
	int	word;

	word = 0;
	while (*str != '\0')
	{
		if (*str != c)
		{
			word++;
			while (*str != c && *str != '\0')
				str++;
		}
		else
			str++;
	}
	return (word);
}

static void		*ft_free(char **word)
{
	int	index;

	index = 0;
	while (word[index])
	{
		free(word[index]);
		index++;
	}
	free(word);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	int		k;
	int		wn;
	char	**rst;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wn = ft_wdc(s, c);
	if (!(rst = (char **)ft_calloc(wn + 1, sizeof(char *))))
		return (NULL);
	while (s[i] != '\0' && j < wn)
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(rst[j] = (char *)malloc(sizeof(char) * (ft_ln(s + i, c) + 1))))
			return (ft_free(rst));
		while (s[i] != c && s[i] != '\0')
			rst[j][k++] = s[i++];
		rst[j++][k] = '\0';
	}
	return (rst);
}
