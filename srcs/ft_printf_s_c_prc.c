/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s_c_prc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 02:33:39 by vtweek            #+#    #+#             */
/*   Updated: 2020/07/23 02:35:31 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_case_prc(t_flags flags)
{
	int ret_val;

	ret_val = 0;
	if (flags.minus_met == 1)
		ft_putchar('%');
	ret_val = ft_width_deal(flags.cur_width, 1, flags.zero_met);
	if (flags.minus_met == 0)
		ft_putchar('%');
	return (ret_val + 1);
}

int			ft_case_c(char c, t_flags flags)
{
	int	ret_val;

	ret_val = 0;
	if (flags.minus_met == 1)
		ft_putchar(c);
	ret_val = ft_width_deal(flags.cur_width, 1, 0);
	if (flags.minus_met == 0)
		ft_putchar(c);
	ret_val += 1;
	return (ret_val);
}

int			ft_put_s(char *s, t_flags flags, size_t len)
{
	int ret_val;

	ret_val = 0;
	if (flags.dot_met >= 0)
	{
		ret_val += ft_width_deal(flags.dot_met, len, 0);
		ret_val += ft_putstr(s, flags.dot_met);
	}
	else
		ret_val += ft_putstr(s, len);
	return (ret_val);
}

int			ft_case_s(char *s, t_flags flags)
{
	int		ret_val;
	char	*s_sub;
	int		len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	s_sub = ft_substr(s, 0, len);
	if (flags.dot_met >= 0 && (size_t)flags.dot_met > (size_t)len)
		flags.dot_met = len;
	ret_val = 0;
	if (flags.minus_met == 1)
		ret_val += ft_put_s(s_sub, flags, len);
	if (flags.dot_met >= 0)
		ret_val += ft_width_deal(flags.cur_width, flags.dot_met, 0);
	else
		ret_val += ft_width_deal(flags.cur_width, len, 0);
	if (flags.minus_met == 0)
		ret_val += ft_put_s(s_sub, flags, len);
	free(s_sub);
	return (ret_val);
}

int			ft_width_deal(int width, int str_len, int zero_flag)
{
	int	i;

	i = 0;
	while (width - str_len > 0)
	{
		if (zero_flag == 0)
			ft_putchar(' ');
		else
			ft_putchar('0');
		width--;
		i++;
	}
	return (i);
}
