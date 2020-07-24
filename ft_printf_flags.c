/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 02:32:11 by vtweek            #+#    #+#             */
/*   Updated: 2020/07/24 21:11:28 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_minus(t_flags *flags)
{
	flags->minus_met = 1;
	flags->zero_met = 0;
}

void		flag_width(t_flags *flags, va_list av)
{
	flags->star_met = 1;
	flags->cur_width = va_arg(av, int);
	if (flags->cur_width < 0)
	{
		flags->minus_met = 1;
		flags->cur_width *= -1;
	}
}

int			flag_dot(const char *s, int i, t_flags *flags, va_list av)
{
	if (s[++i] == '*')
	{
		flags->dot_met = va_arg(av, int);
		i++;
	}
	else
	{
		flags->dot_met = 0;
		while (ft_isdigit(s[i]))
			flags->dot_met = (flags->dot_met * 10) + (s[i++] - 48);
	}
	return (i);
}

void		flag_digit(char c, t_flags *flags)
{
	if (flags->star_met == 1)
		flags->cur_width = 0;
	flags->cur_width = (flags->cur_width * 10) + (c - 48);
}

t_flags		set_dflt_flags(void)
{
	t_flags		flag_met;

	flag_met.cur_width = 0;
	flag_met.minus_met = 0;
	flag_met.star_met = 0;
	flag_met.dot_met = -1;
	flag_met.var_type_met = 0;
	flag_met.zero_met = 0;
	return (flag_met);
}
