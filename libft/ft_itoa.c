/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:56:15 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:56:21 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_d_len(int numb)
{
	int len;

	len = 0;
	if (numb == 0)
		len = 1;
	while (numb != 0)
	{
		numb = numb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;


	if (n >= 0)
		n = (~n) + 1;
	len = ft_d_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[0] = '0';
	while (n != 0)
	{
		len--;
		str[len] = ~(n % 10) + 1 + '0';
		n = n / 10;
	}
	return (str);
}
