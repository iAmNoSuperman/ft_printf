#include "../include/ft_printf.h"

int 	ft_put_u(char *nbr_str, t_flags flags, size_t len)
{
	int 	done;

	done = 0;
	if (flags.dot_met >= 0)
		done += ft_width_deal(flags.dot_met - 1, len - 1, 1);
	done += ft_putstr(nbr_str, len);
	return (done);
}

int	ft_flag_deal_u(char *nbr_str, t_flags flags)
{
	size_t	len;
	int 			done;

	len = ft_strlen(nbr_str);
	done = 0;
	if (flags.minus_met == 1)
		done += ft_put_u(nbr_str, flags, len);
	if (flags.dot_met >= 0 && (size_t)flags.dot_met < len)
		flags.dot_met = len;
	if (flags.dot_met >= 0)
	{
		flags.cur_width -= flags.dot_met;
		done += ft_width_deal(flags.cur_width, 0 , 0);
	}
	else
		done += ft_width_deal(flags.cur_width, len, flags.zero_met);
	if (flags.minus_met == 0)
		done += ft_put_u(nbr_str, flags, len);
	return (done);
}

int			ft_case_u(unsigned int nbr, t_flags flags)
{
	char	*nbr_str;
	int		done;

	done = 0;
	if (flags.dot_met == 0 && nbr == 0)
	{
		done += ft_width_deal(flags.cur_width, 0, 0);
		return (done);
	}
	nbr_str = ft_itoa_base(nbr, 10, 1);
	done += ft_flag_deal_u(nbr_str, flags);
	free(nbr_str);
	return (done);
}

int 		ft_put_p(char *str, t_flags flags, size_t len)
{
	int 	done;

	done = 0;
	done += ft_putstr("0x", 2);
	if (flags.dot_met >= 0)
	{
		done += ft_width_deal(flags.dot_met, len, 1);
		done += ft_putstr(str, flags.dot_met);
	}
	else
		done += ft_putstr(str, len);
	return (done);
}

int 		ft_case_p(unsigned long long nbr, t_flags flags)
{
	int		done;
	size_t 	len;
	char 	*str;

	done = 0;
	if (nbr == 0 && flags.dot_met == 0)
	{
		done +=ft_putstr("0x", 2);
		return (done += ft_width_deal(flags.cur_width, 0 , 1));
	}
	if (nbr == 0 && flags.dot_met >= 0)
		flags.cur_width -= 1;
	str = ft_itoa_base(nbr, 16, 1);
	len = ft_strlen(str);
	if ((size_t)flags.dot_met < len)
		flags.dot_met = len;
	if (flags.minus_met == 1)
		done += ft_put_p(str, flags, len);
	done += ft_width_deal(flags.cur_width, len + 2, 0);
	if (flags.minus_met == 0)
		done += ft_put_p(str, flags, len);
	free (str);
	return (done);
}