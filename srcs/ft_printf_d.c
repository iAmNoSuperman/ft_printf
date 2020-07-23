#include "../include/ft_printf.h"

int	ft_put_d(char *nbr_str, int tmp, t_flags flags, size_t len)
{
	int 	done;

	done = 0;
	if (tmp < 0 && (flags.dot_met >= 0 || flags.zero_met == 0))
		done += ft_putchar ('-');
	if (flags.dot_met >= 0)
		done += ft_width_deal(flags.dot_met - 1, len - 1, 1);
	done += ft_putstr(nbr_str, len);
	return (done);
}

int ft_flag_deal_d(char *nbr_str, int tmp, t_flags flags)
{
	size_t 			len;
	int 			done;

	len = ft_strlen(nbr_str);
	done = 0;
	if (flags.minus_met == 1)
		done += ft_put_d(nbr_str, tmp, flags, len);
	if (flags.dot_met >= 0 && (size_t)flags.dot_met < len)
		flags.dot_met = len;
	if (flags.dot_met >= 0)
	{
		flags.cur_width -= flags.dot_met;
		done += ft_width_deal(flags.cur_width, 0 , 0);
	}
	else {
		if (tmp < 0 && flags.zero_met == 0)
			len++;
		if(flags.zero_met > 0 && flags.minus_met > 0)
			flags.zero_met = 0;
		done += ft_width_deal(flags.cur_width, len, flags.zero_met);
	}
	if (flags.minus_met == 0)
		done += ft_put_d(nbr_str, tmp, flags, len);
	return (done);
}

int 		ft_case_d(int nbr, t_flags flags)
{
	char 	*nbr_str;
	int		tmp;
	int		done;

	done = 0;
	tmp = nbr;
	if (flags.dot_met == 0 && nbr == 0)
	{
		done += ft_width_deal(flags.cur_width, 0, 0);
		return (done);
	}
	if (nbr < 0 && (flags.dot_met >= 0 || flags.zero_met == 1))
	{
		if (flags.zero_met == 1 && flags.dot_met <= -1)
			done += ft_putchar('-');
		flags.cur_width--;
		nbr *= -1;
	}
	nbr_str = ft_itoa(nbr);
	done += ft_flag_deal_d(nbr_str, tmp, flags);
	free(nbr_str);
	return (done);
}