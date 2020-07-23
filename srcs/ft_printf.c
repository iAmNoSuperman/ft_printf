/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 02:21:04 by vtweek            #+#    #+#             */
/*   Updated: 2020/07/23 02:53:19 by vtweek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			var_type(int c)
{
	if ((c == 'c') || (c == 'd') || (c == 'i') || (c == 'p') || (c == 's')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
		return (1);
	return (0);
}

int			flag_type_rit(const char *s, int i, t_flags *f, va_list av)
{
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && !var_type(s[i]) && (s[i] != '-')
				&& (s[i] != '0') && (s[i] != '.') && (s[i] != '*'))
			break ;
		if (s[i] == '-')
			*f = flag_minus(*f);
		if (s[i] == '.')
			i = flag_dot(s, i, f, av);
		if (s[i] == '*')
			*f = flag_width(*f, av);
		if (s[i] == '0' && f->cur_width == 0 && f->minus_met == 0)
			f->zero_met = 1;
		if (var_type(s[i]))
		{
			f->var_type_met = s[i];
			break ;
		}
		if (ft_isdigit(s[i]))
			*f = flag_digit(s[i], *f);
		i++;
	}
	return (i);
}

int			var_type_deal(int c, t_flags flags, va_list av)
{
	int		done;

	done = 0;
	if (c == 'c')
		done += ft_case_c(va_arg(av, int), flags);
	else if (c == 'd' || c == 'i')
		done += ft_case_d(va_arg(av, int), flags);
	else if (c == 'p')
		done += ft_case_p(va_arg(av, unsigned long long), flags);
	else if (c == 's')
		done += ft_case_s(va_arg(av, char *), flags);
	else if (c == 'u')
		done += ft_case_u(va_arg(av, unsigned int), flags);
	else if (c == 'x')
		done += ft_case_x(va_arg(av, unsigned int), 1, flags);
	else if (c == 'X')
		done += ft_case_x(va_arg(av, unsigned int), 0, flags);
	else if (c == '%')
		done += ft_case_prc(flags);
	return (done);
}

int			ft_read_str(const char *s, va_list av)
{
	t_flags		flags_met;
	int			done;
	int			i;

	done = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			done += ft_putchar(s[i]);
		else if (s[i] == '%' && s[i + 1])
		{
			i++;
			flags_met = set_dflt_flags();
			i = flag_type_rit(s, i, &flags_met, av);
			if (var_type(s[i]))
				done += var_type_deal((char)flags_met.var_type_met,
						flags_met, av);
			else if (s[i])
				done += ft_putchar(s[i]);
		}
		i++;
	}
	return (done);
}

int			ft_printf(const char *s, ...)
{
	va_list		av;
	int			done;

	if (s == NULL)
		return (-1);
	va_start(av, s);
	done = ft_read_str(s, av);
	va_end(av);
	return (done);
}
