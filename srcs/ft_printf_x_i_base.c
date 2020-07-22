#include "../include/ft_printf.h"

int		    ft_uxX_len(unsigned long long numb, int base)
{
	int len;

	len = 0;
	if (numb == 0)
		len = 1;
	while (numb != 0)
	{
		numb = numb / base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(unsigned long long n, int base, int flag)
{
	int						len;
	unsigned long long		reminder;
	char					*str;
	char					*letters_x;
	char 					*letters_x_grand;

	if (n == 0)
		return (ft_strdup("0"));
	len = 0;
	letters_x = "0123456789abcdef";
	letters_x_grand = "0123456789ABCDEF";
	len += ft_uxX_len(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (n > 0)
	{
		len--;
		reminder = n % base;
		str[len] = (flag == 1) ? letters_x[reminder] : letters_x_grand[reminder];
		n = n / base;
	}
	return (str);
}

int 	ft_put_x(char *x, t_flags flags, size_t len)
{
	int 	done;

	done = 0;
	if (flags.dot_met >= 0)
		done += ft_width_deal(flags.dot_met - 1, len - 1, 1);
	done += ft_putstr(x, len);
	return (done);
}

int	ft_flag_deal_x(char *x, t_flags flags)
{
	size_t	len;
	int 			done;

	len = ft_strlen(x);
	done = 0;
	if (flags.minus_met == 1)
		done += ft_put_x(x, flags, len);
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
		done += ft_put_x(x, flags, len);
	return (done);
}

int 		ft_case_x(unsigned int nbr, int lower, t_flags flags)
{
	int 	done;
	char	*x;

	done = 0;
	if (flags.dot_met == 0 && nbr == 0)
	{
		done = ft_width_deal(flags.cur_width, 0, 0);
		return (done);
	}
	x = ft_itoa_base((unsigned long long)nbr, 16, lower);
	done += ft_flag_deal_x(x, flags);
	free (x);
	return (done);
}