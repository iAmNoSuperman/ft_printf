/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:58:00 by vtweek            #+#    #+#             */
/*   Updated: 2020/05/28 11:34:25 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char *s, int length)
{
	int index;

	index = 0;
	while(*(s + index) != '\0' && index < length)
	{
		ft_putchar(*(s + index));
		index += 1;
	}
	return (index);
}

