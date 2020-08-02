/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 02:36:02 by vtweek            #+#    #+#             */
/*   Updated: 2020/07/23 02:39:38 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_u(char *nbr_str, t_flags flags, size_t len)
{
	int		ret_val;

	ret_val = 0;
	if (flags.dot_met >= 0)
		ret_val += ft_width_deal(flags.dot_met - 1, len - 1, 1);
	ret_val += ft_putstr(nbr_str, len);
	return (ret_val);
}

int		ft_flag_deal_u(char *nbr_str, t_flags flags)
{
	size_t		len;
	int			ret_val;

	len = ft_strlen(nbr_str);
	ret_val = 0;
	if (flags.minus_met == 1)
		ret_val += ft_put_u(nbr_str, flags, len);
	if (flags.dot_met >= 0 && (size_t)flags.dot_met < len)
		flags.dot_met = len;
	if (flags.dot_met >= 0)
	{
		flags.cur_width -= flags.dot_met;
		ret_val += ft_width_deal(flags.cur_width, 0, 0);
	}
	else
		ret_val += ft_width_deal(flags.cur_width, len, flags.zero_met);
	if (flags.minus_met == 0)
		ret_val += ft_put_u(nbr_str, flags, len);
	return (ret_val);
}

int		ft_case_u(unsigned int nbr, t_flags flags)
{
	char	*nbr_str;
	int		ret_val;

	ret_val = 0;
	if (flags.dot_met == 0 && nbr == 0)
	{
		ret_val += ft_width_deal(flags.cur_width, 0, 0);
		return (ret_val);
	}
	nbr_str = ft_itoa_base(nbr, 10, 1);
	ret_val += ft_flag_deal_u(nbr_str, flags);
	free(nbr_str);
	return (ret_val);
}

int		ft_put_p(char *str, t_flags flags, size_t len)
{
	int		ret_val;

	ret_val = 0;
	ret_val += ft_putstr("0x", 2);
	if (flags.dot_met >= 0)
	{
		ret_val += ft_width_deal(flags.dot_met, len, 1);
		ret_val += ft_putstr(str, flags.dot_met);
	}
	else
		ret_val += ft_putstr(str, len);
	return (ret_val);
}

int		ft_case_p(unsigned long long nbr, t_flags flags)
{
	int			ret_val;
	size_t		len;
	char		*str;

	ret_val = 0;
	if (nbr == 0 && flags.dot_met == 0)
	{
		ret_val += ft_putstr("0x", 2);
		return (ret_val += ft_width_deal(flags.cur_width, 0, 1));
	}
	if (nbr == 0 && flags.dot_met >= 0)
		flags.cur_width -= 1;
	str = ft_itoa_base(nbr, 16, 1);
	len = ft_strlen(str);
	if ((size_t)flags.dot_met < len)
		flags.dot_met = len;
	if (flags.minus_met == 1)
		ret_val += ft_put_p(str, flags, len);
	ret_val += ft_width_deal(flags.cur_width, len + 2, 0);
	if (flags.minus_met == 0)
		ret_val += ft_put_p(str, flags, len);
	free(str);
	return (ret_val);
}
