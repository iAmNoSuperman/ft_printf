#include "../include/ft_printf.h"

//static int		ft_d_len(int numb)
//{
//	int len;
//
//	len = 0;
//	if (numb == 0)
//		len = 1;
//	while (numb != 0)
//	{
//		numb = numb / 10;
//		len++;
//	}
//	return (len);
//}
//
//char			*ft_itoa(int n)
//{
//	int		len;
//	char	*str;
//
//
//	if (n >= 0)
//		n = (~n) + 1;
//	len = ft_d_len(n);
//	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
//		return (NULL);
//	str[len] = '\0';
//	while (n != 0)
//	{
//		len--;
//		str[len] = ~(n % 10) + 1 + '0';
//		n = n / 10;
//	}
//	return (str);
//}

int	ft_put_d(char *nbr_str, int tmp, t_flags flags, size_t len)
{
	int 	done;

	done = 0;
	if (tmp < 0 && (flags.dot_met >= 0 || flags.zero_met == 0))				//was && here
		ft_putchar ('-');
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
	if (nbr < 0 && (flags.dot_met >= 0 || flags.zero_met == 1)) //was && in first
	{
		if (flags.zero_met == 1 && flags.dot_met == -1)		// was &&
			ft_putchar('-');
		flags.cur_width--;
		nbr *= -1;
		done++;
	}
	nbr_str = ft_itoa(nbr);
	done += ft_flag_deal_d(nbr_str, tmp, flags);
	free(nbr_str);
	return (done);
}