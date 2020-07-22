/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:53:14 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/25 18:53:20 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_maxlong(int flag)
{
	if (flag == -1)
		return (0);
	else
		return (-1);
}

int			ft_atoi(char *a)
{
	int						n;
	unsigned long int		numb;
	long long int			sign;

	numb = 0;
	sign = 1;
	n = 0;
	while ((a[n] >= 9 && a[n] <= 13) || a[n] == 32)
		n++;
	if (a[n] == '-' || a[n] == '+')
	{
		if (a[n] == '-')
			sign = -1;
		n++;
	}
	while (a[n] >= '0' && a[n] <= '9')
	{
		numb = numb * 10 + (a[n] - '0');
		n++;
	}
	if (numb > 9223372036854775807)
		numb = ft_maxlong(sign);
	if (sign == 1)
		return (numb);
	return (-numb);
}
