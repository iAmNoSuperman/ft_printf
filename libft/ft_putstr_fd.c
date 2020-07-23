/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:58:00 by vtweek            #+#    #+#             */
/*   Updated: 2020/07/23 13:14:00 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char *s, int length)
{
	int	index;

	index = 0;
	while (*(s + index) != '\0' && index < length)
	{
		ft_putchar(*(s + index));
		index++;
	}
	return (index);
}
