
#include <stdio.h>
#include <limits.h>
#include "./include/ft_printf.h"

/*
char	*ft_strdup(char *str)
{
	char	*c;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(c = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		c[i] = str[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

size_t	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr(char *s, int length)
{
	write(1, s, length);
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	size_t			fact_len;
	char			*result;

	index = 0;
	fact_len = 0;
	if (!s || start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	while (fact_len < len && s[fact_len + start] != '\0')
		fact_len++;
	if (!(result = (char*)malloc(sizeof(char) * (fact_len + 1))))
		return (NULL);
	while (fact_len > 0 && s[start] != '\0')
	{
		result[index] = s[start];
		start++;
		index++;
		fact_len--;
	}
	result[index] = '\0';
	return (result);
}
*/

/*
static int		ft_d_len(int numb)
{
	int len;

	len = 0;
	if (numb == 0)
		len = 1;
	while (numb != 0)
	{
		numb = numb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;


	if (n >= 0)
		n = (~n) + 1;
	len = ft_d_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (n != 0)
	{
		len--;
		str[len] = ~(n % 10) + 1 + '0';
		n = n / 10;
	}
	return (str);
}

static int	ft_put_d(char *nbr_str, int tmp, t_flags flags, size_t len)
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

static int ft_flag_deal_d(char *nbr_str, int tmp, t_flags flags)
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
*/

/*
int		ft_uxX_len(unsigned long long numb, int base)
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
*/
/*int 		ft_width_deal(int width, int str_len, int zero_flag)
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
 */
/*
int 		ft_case_c(char c, t_flags flags)
{
	int	done;

	done = 0;
	if (flags.minus_met == 1)
		ft_putchar(c);
	done = ft_width_deal(flags.cur_width, 1, 0);
	if (flags.minus_met == 0)
		ft_putchar(c);
	return (done + 1);
}

int 		ft_put_s(char *s, t_flags flags, size_t len)
{
	int done;

	done = 0;
	if (flags.dot_met >= 0)
	{
		done += ft_width_deal(flags.dot_met, len, 0);
		done += ft_putstr(s, flags.dot_met);
	} else
		done += ft_putstr(s, len);
	return (done);
}

int 		ft_case_s(char *s, t_flags flags)
{
	int 	done;
	char 	*s_sub;
	int 	len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	s_sub = ft_substr(s, 0, len);
	if (flags.dot_met >= 0 && (size_t)flags.dot_met > len)
		flags.dot_met = len;
	done = 0;
	if (flags.minus_met == 1)
		done += ft_put_s(s_sub, flags, len);
	if (flags.dot_met >= 0)
		done += ft_width_deal(flags.cur_width, flags.dot_met, 0);
	else
		done += ft_width_deal(flags.cur_width, len, 0);
	if (flags.minus_met == 0)
		done += ft_put_s(s_sub, flags, len);
	free(s_sub);
	return (done);
}
*/

/*
static int 	ft_put_u(char *nbr_str, t_flags flags, size_t len)
{
	int 	done;

	done = 0;
	if (flags.dot_met >= 0)
		done += ft_width_deal(flags.dot_met - 1, len - 1, 1);
	done += ft_putstr(nbr_str, len);
	return (done);
}

static int	ft_flag_deal_u(char *nbr_str, t_flags flags)
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
*/
/*
static int 	ft_put_x(char *x, t_flags flags, size_t len)
{
	int 	done;

	done = 0;
	if (flags.dot_met >= 0)
		done += ft_width_deal(flags.dot_met - 1, len - 1, 1);
	done += ft_putstr(x, len);
	return (done);
}

static int	ft_flag_deal_x(char *x, t_flags flags)
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
		done += ft_put_u(x, flags, len);
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

int 		ft_case_prc(t_flags flags)
{
	int done;

	done = 0;
	if (flags.minus_met == 1)
		ft_putchar('%');
	done = ft_width_deal(flags.cur_width, 1, flags.zero_met);
	if (flags.minus_met == 0)
		ft_putchar('%');
	return (done + 1);
}

*/

//static void check_zero(t_flags *flags)
//{
//	if (flags->zero_fill == 1 && flags->dot_met == -1)
//		ft_putchar('-');
//	flags->zero_fill = 1;
//	flags->cur_width--;
//}


/*
//TODO flags initialize functions

t_flags		flag_minus(t_flags flags)
{
	flags.minus_met = 1;
	flags.zero_met = 0;
	return (flags);
}

t_flags		flag_width(t_flags flags, va_list av)
{
	flags.star_met = 1;
	flags.cur_width = va_arg(av, int);
	if (flags.cur_width < 0)
	{
		flags.minus_met = 1;
		flags.cur_width *= -1;
	}
	return (flags);
}
													//TODO FIX HERE -> sign!
int			flag_dot(const char *s, int i, t_flags *flags, va_list av)
{
	if (s[++i] == '*')
	{
		flags->dot_met = va_arg(av, int);
		i++;
	}
	else
	{
		flags->dot_met= 0;
		while(ft_isdigit(s[i]))
			flags->dot_met = (flags->dot_met * 10) + (s[i++] - 48);
	}
	return (i);
}

t_flags		flag_digit(char c, t_flags flags)
{
	if (flags.star_met == 1)
		flags.cur_width = 0;
	flags.cur_width = (flags.cur_width * 10) + (c - 48);
	return (flags);
}

//TODO some flags setup + translate functions

t_flags		set_dflt_flags(void)
{
	t_flags		flag_met;

	flag_met.var_type_met = 0;			// 'd' || 'c' || 's' ||etc
	flag_met.minus_met = 0;		// 0 no left adj yet
	flag_met.zero_met = 0;			// 0 no 0 had been met
	flag_met.cur_width = 0;		//10
	flag_met.star_met = 0;			// 0 no stars had been met
	flag_met.dot_met = -1;			// -1 no dots had been met
	return (flag_met);
}

*/

/*
int 		var_type(int c)
{
	if ((c == 'c') || (c == 's') || (c == 'd') || (c == 'i') || (c == 'p')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'))
		return (1);
	return (0);
}

int 		flag_type_read(const char *s, int i, t_flags *flags, va_list av)
{
	while(s[i])
	{
		if (!ft_isdigit(s[i]) && !var_type(s[i]) && (s[i] != '-') && (s[i] != '0')
			&& (s[i] != '.') && (s[i] != '*'))
			break ;
		if (s[i] == '-')
			*flags = flag_minus(*flags);
		if (s[i] == '0' && flags->cur_width == 0 && flags->minus_met == 0)
			flags->zero_met = 1;
		if (s[i] == '.')
			i = flag_dot(s, i, flags, av);
		if (s[i] == '*')
			*flags = flag_width(*flags, av);
		if (ft_isdigit(s[i]))
			*flags = flag_digit(s[i], *flags);
		if (var_type(s[i]))
		{
			flags->var_type_met = s[i];
			break ;
		}
			i++;
	}
	return (i);
}

int 		var_type_deal(int c, t_flags flags, va_list av)
{
	int		done;

	done = 0;
	if (c == 'c')
		done += ft_case_c(va_arg(av, int), flags);
	else if (c == 's')
		done += ft_case_s(va_arg(av, char *), flags);
	else if (c == 'd' || c == 'i')
		done += ft_case_d(va_arg(av, int), flags);
	else if (c == 'p')
		done += ft_case_p(va_arg(av, unsigned long long), flags);
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



//TODO printf + read the original string functions

int 		ft_read_str(const char *s, va_list av)
{
	t_flags		flags_met;
	int 		done;
	int 		i;

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
			i = flag_type_read(s, i, &flags_met, av);
			if (var_type(s[i]))
				done += var_type_deal((char) flags_met.var_type_met, flags_met, av);
			else if(s[i])
				done += ft_putchar(s[i]);
		}
		i++;
	}
	return (done);
}

int 		ft_printf(const char *s, ...)
{
	va_list	av;
	int 	done;

	if (s == NULL)
		return (-1);
	va_start(av, s);
	done = ft_read_str(s, av);
	va_end(av);
	return (done);
}

*/

int		main(void)
{
	int		*tab = malloc(sizeof(int) * 10);
	int		*tab2 = malloc(0);

	ft_printf("--------------------%%c--------------------\n");		//Perfect
	printf("01) Vrai PRINTF : |%c|\n", 'a');
	ft_printf("01) Mon PRINTF  : |%c|\n", 'a');
	printf("02) Vrai PRINTF : |%-c|\n", 'z');
	ft_printf("02) Mon PRINTF  : |%-c|\n", 'z');
	printf("03) Vrai PRINTF : |%-----c|\n", '!');
	ft_printf("03) Mon PRINTF  : |%-----c|\n", '!');
	printf("04) Vrai PRINTF : |%5c|\n", 'R');
	ft_printf("04) Mon PRINTF  : |%5c|\n", 'R');
	printf("05) Vrai PRINTF : |%-5c|\n", 'R');
	ft_printf("05) Mon PRINTF  : |%-5c|\n", 'R');
	printf("06) Vrai PRINTF : |%1c|\n", '3');
	ft_printf("06) Mon PRINTF  : |%1c|\n", '3');
	printf("07) Vrai PRINTF : |%c|\n", '\0');
	ft_printf("07) Mon PRINTF  : |%c|\n", '\0');
	printf("08) Vrai PRINTF : |%5c|\n", '\0');
	ft_printf("08) Mon PRINTF  : |%5c|\n", '\0');
	printf("09) Vrai PRINTF : |%-5c|\n", '\0');
	ft_printf("09) Mon PRINTF  : |%-5c|\n", '\0');
	printf("10) Vrai PRINTF : |%1c|\n", '\0');
	ft_printf("10} Mon PRINTF  : |%1c|\n", '\0');


	ft_printf("--------------------%%s--------------------\n");			//Perfect
	printf("01) Vrai PRINTF : |%s|\n", "salut");
	ft_printf("01) Mon PRINTF  : |%s|\n", "salut");
	printf("02) Vrai PRINTF : |%-s|\n", "test");
	ft_printf("02) Mon PRINTF  : |%-s|\n", "test");
	printf("03) Vrai PRINTF : |%---------s|\n", "test2");
	ft_printf("03) Mon PRINTF  : |%----------s|\n", "test2");
	printf("04) Vrai PRINTF : |%10s|\n", "42");
	ft_printf("04) Mon PRINTF  : |%10s|\n", "42");
	printf("05) Vrai PRINTF : |%-10s|\n", "42");
	ft_printf("05) Mon PRINTF  : |%-10s|\n", "42");
	printf("06) Vrai PRINTF : |%2s|\n", "string");
	ft_printf("06) Mon PRINTF  : |%2s|\n", "string");
	printf("07) Vrai PRINTF : |%-2s|\n", "string");
	ft_printf("07) Mon PRINTF  : |%-2s|\n", "string");
	printf("08) Vrai PRINTF : |%.15s|\n", "precision");
	ft_printf("08) Mon PRINTF  : |%.15s|\n", "precision");
	printf("09) Vrai PRINTF : |%.4s|\n", "precision");
	ft_printf("09) Mon PRINTF  : |%.4s|\n", "precision");
	printf("10) Vrai PRINTF : |%.0s|\n", "precision");
	ft_printf("10) Mon PRINTF  : |%.0s|\n", "precision");
	printf("11) Vrai PRINTF : |%s|\n", "\0\0\0\0\0");
	ft_printf("11) Mon PRINTF  : |%s|\n", "\0\0\0\0\0");
	printf("12) Vrai PRINTF : |%10s|\n", "\0\0\0\0\0");
	ft_printf("12) Mon PRINTF  : |%10s|\n", "\0\0\0\0\0");
	printf("13) Vrai PRINTF : |%s|\n", "");
	ft_printf("13) Mon PRINTF  : |%s|\n", "");
	printf("14) Vrai PRINTF : |%-.2s|\n", "boom");
	ft_printf("14) Mon PRINTF  : |%-.2s|\n", "boom");
	printf("15) Vrai PRINTF : |%10.8s|\n", "google");
	ft_printf("15) Mon PRINTF  : |%10.8s|\n", "google");
	printf("16) Vrai PRINTF : |%10.2s|\n", "twitter");
	ft_printf("16) Mon PRINTF  : |%10.2s|\n", "twitter");
	printf("17) Vrai PRINTF : |%2.10s|\n", "samsung");
	ft_printf("17) Mon PRINTF  : |%2.10s|\n", "samsung");
	printf("18) Vrai PRINTF : |%2.5s|\n", "printf");
	ft_printf("18) Mon PRINTF  : |%2.5s|\n", "printf");
	printf("19) Vrai PRINTF : |%-10.2s|\n", "424242424242");
	ft_printf("19) Mon PRINTF  : |%-10.2s|\n", "424242424242");
	printf("20) Vrai PRINTF : |%1.0s|\n", "123456789");
	ft_printf("20) Mon PRINTF  : |%1.0s|\n", "123456789");
	printf("20) Vrai PRINTF : |%-1.0s|\n", "123456789");
	ft_printf("20) Mon PRINTF  : |%-1.0s|\n", "123456789");
	printf("21) Vrai PRINTF : |%s|\n", NULL);
	ft_printf("21) Mon PRINTF  : |%s|\n", NULL);
	printf("22) Vrai PRINTF : |%10s|\n", NULL);
	ft_printf("22) Mon PRINTF  : |%10s|\n", NULL);
	printf("23) Vrai PRINTF : |%-10s|\n", NULL);
	ft_printf("23) Mon PRINTF  : |%-10s|\n", NULL);
	printf("24) Vrai PRINTF : |%.2s|\n", NULL);
	ft_printf("24) Mon PRINTF  : |%.2s|\n", NULL);
	printf("25) Vrai PRINTF : |%10.8s|\n", NULL);
	ft_printf("25) Mon PRINTF  : |%10.8s|\n", NULL);
	printf("26) Vrai PRINTF : |%10.2s|\n", NULL);
	ft_printf("26) Mon PRINTF  : |%10.2s|\n", NULL);
	printf("27) Vrai PRINTF : |%2.10s|\n", NULL);
	ft_printf("27) Mon PRINTF  : |%2.10s|\n", NULL);
	printf("28) Vrai PRINTF : |%2.5s|\n", NULL);
	ft_printf("28) Mon PRINTF  : |%2.5s|\n", NULL);
	printf("29) Vrai PRINTF : |%-10.2s|\n", NULL);
	ft_printf("29) Mon PRINTF  : |%-10.2s|\n", NULL);
	printf("30) Vrai PRINTF : |%1.0s|\n", NULL);
	ft_printf("30) Mon PRINTF  : |%1.0s|\n", NULL);
	printf("31) Vrai PRINTF : |%-1.s|\n", NULL);
	ft_printf("31) Mon PRINTF  : |%-1.s|\n", NULL);


	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("%4.2s %-1.s\n" , "coco", NULL);
	ft_printf("%4.2s %-1.s\n" , "coco", NULL);
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL);
	ft_printf("Coucou %.0s\n%s%---12s\n", "hi", "coco", NULL);
//	ft_printf("--------------------%%p--------------------\n");			//perfect
//	printf("test %-7C %007d%-10.2ls!!\n", 0xd777, 0x45, "L〻");
//	ft_printf("test %-7C %007d%-10.2ls!!\n", 0xd777, 0x45, "L〻");
//	ft_printf("--------------------%%p--------------------\n");			//perfect
//	printf("%+%\n");
//	ft_printf("%+%\n");
	ft_printf("--------------------%%p--------------------\n");			//perfect
//	printf("titi % +---12.5% et%%%0004% et %+1%\n");
//	ft_printf("titi % +---12.5% et%%%0004% et %+1%\n");
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("|%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu", "12345", "hu");
	ft_printf("|%1.4s| et |%-6.8s| et |%4.2s|\n", "tuuu", "12345", "hu");
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	ft_printf("hello ca%----4c %1c va %10c%-c ??\n", '\0', '\n', (char)564, 0);
	ft_printf("--------------------%%p--------------------\n");			//perfect
	printf("01) Vrai PRINTF : |%p|\n", "salut");
	ft_printf("01) Mon PRINTF  : |%p|\n", "salut");
	printf("02) Vrai PRINTF : |%-p|\n", tab2);
	ft_printf("02) Mon PRINTF  : |%-p|\n", tab2);
	printf("03) Vrai PRINTF : |%---------p|\n", "test2");
	ft_printf("03) Mon PRINTF  : |%----------p|\n", "test2");
	printf("04) Vrai PRINTF : |%10p|\n", "42");
	ft_printf("04) Mon PRINTF  : |%10p|\n", "42");
	printf("05) Vrai PRINTF : |%-10p|\n", "42");
	ft_printf("05) Mon PRINTF  : |%-10p|\n", "42");
	printf("06) Vrai PRINTF : |%2p|\n", tab);
	ft_printf("06) Mon PRINTF  : |%2p|\n", tab);
	printf("07) Vrai PRINTF : |%-2p|\n", tab);
	ft_printf("07) Mon PRINTF  : |%-2p|\n", tab);
	printf("11) Vrai PRINTF : |%p|\n", "\0\0\0\0\0");
	ft_printf("11) Mon PRINTF  : |%p|\n", "\0\0\0\0\0");
	printf("12) Vrai PRINTF : |%20p|\n", "\0\0\0\0\0");
	ft_printf("12) Mon PRINTF  : |%20p|\n", "\0\0\0\0\0");
	printf("13) Vrai PRINTF : |%p|\n", "");
	ft_printf("13) Mon PRINTF  : |%p|\n", "");
	printf("14) Vrai PRINTF : |%p|\n", NULL);
	ft_printf("14) Mon PRINTF  : |%p|\n", NULL);
	printf("15) Vrai PRINTF : |%10p|\n", NULL);
	ft_printf("15) Mon PRINTF  : |%10p|\n", NULL);
	printf("16) Vrai PRINTF : |%-10p|\n", NULL);
	ft_printf("16) Mon PRINTF  : |%-10p|\n", NULL);
	free(tab);
	free(tab2);


	ft_printf("--------------------%%d-et-%%i--------------------\n");	//perfect
	printf("01) Vrai PRINTF : |%d|\n", 42);
	ft_printf("01) Mon PRINTF  : |%d|\n", 42);
	printf("02) Vrai PRINTF : |%i|\n", 42);
	ft_printf("02) Mon PRINTF  : |%i|\n", 42);
//	printf("03) Vrai PRINTF : |%+d|\n", 42);
//	ft_printf("03) Mon PRINTF  : |%+d|\n", 42);
	printf("04) Vrai PRINTF : |%-d|\n", 42);
	ft_printf("04) Mon PRINTF  : |%-d|\n", 42);
	printf("05) Vrai PRINTF : |%10d|\n", 100);
	ft_printf("05) Mon PRINTF  : |%10d|\n", 100);
	printf("06) Vrai PRINTF : |%-10d|\n", 64);
	ft_printf("06) Mon PRINTF  : |%-10d|\n", 64);
	printf("07) Vrai PRINTF : |%.10d|\n", 100);
	ft_printf("07) Mon PRINTF  : |%.10d|\n", 100);
	printf("08) Vrai PRINTF : |%10.5d|\n", 100);
	ft_printf("08) Mon PRINTF  : |%10.5d|\n", 100);
	printf("09) Vrai PRINTF : |%5.10d|\n", 64);
	ft_printf("09) Mon PRINTF  : |%5.10d|\n", 64);
	printf("10) Vrai PRINTF : |%1.1d|\n", 16);
	ft_printf("10) Mon PRINTF  : |%1.1d|\n", 16);
	printf("11) Vrai PRINTF : |%+10d|\n", 50);
	ft_printf("11) Mon PRINTF  : |%+10d|\n", 50);
	printf("12) Vrai PRINTF : |%+2d|\n", 50);
	ft_printf("12) Mon PRINTF  : |%+2d|\n", 50);
	printf("13) Vrai PRINTF : |%+.10d|\n", 50);
	ft_printf("13) Mon PRINTF  : |%+.10d|\n", 50);

	printf("14) Vrai PRINTF : |%+.2d|\n", 50);
	ft_printf("14) Mon PRINTF  : |%+.2d|\n", 50);
	printf("15) Vrai PRINTF : |%          d|\n", 1);
	ft_printf("15) Mon PRINTF  : |%          d|\n", 1);
	printf("16) Vrai PRINTF : |% -d|\n", 1);
	ft_printf("16) Mon PRINTF  : |% -d|\n", 1);
	printf("17) Vrai PRINTF : |%-+d|\n", 32);
	ft_printf("17) Mon PRINTF  : |%-+d|\n", 32);
	printf("18) Vrai PRINTF : |%+-d|\n", 32);
	ft_printf("18) Mon PRINTF  : |%+-d|\n", 32);
	printf("19) Vrai PRINTF : |%-+10d|\n", 42);
	ft_printf("19) Mon PRINTF  : |%-+10d|\n", 42);
	printf("20) Vrai PRINTF : |%-+.10d|\n", 42);
	ft_printf("20) Mon PRINTF  : |%-+.10d|\n", 42);
	printf("21) Vrai PRINTF : |%d|\n", -42);
	ft_printf("21) Mon PRINTF  : |%d|\n", -42);
	printf("22) Vrai PRINTF : |%10d|\n", -42);
	ft_printf("22) Mon PRINTF  : |%10d|\n", -42);
	printf("23) Vrai PRINTF : |%.10d|\n", -42);
	ft_printf("23) Mon PRINTF  : |%.10d|\n", -42);
	printf("24) Vrai PRINTF : |%+d|\n", -10);
	ft_printf("24) Mon PRINTF  : |%+d|\n", -10);
	printf("25) Vrai PRINTF : |%10.5d|\n", -16);
	ft_printf("25) Mon PRINTF  : |%10.5d|\n", -16);
	printf("26) Vrai PRINTF : |%5.10d|\n", -16);
	ft_printf("26) Mon PRINTF  : |%5.10d|\n", -16);
	printf("27) Vrai PRINTF : |%1.1d|\n", -20);
	ft_printf("27) Mon PRINTF  : |%1.1d|\n", -20);
	printf("29) Vrai PRINTF : |%-10d|\n", -50);
	ft_printf("29) Mon PRINTF  : |%-10d|\n", -50);
	printf("30) Vrai PRINTF : |%++++++++++d|\n", 69);
	ft_printf("30) Mon PRINTF  : |%++++++++++d|\n", 69);
	printf("31) Vrai PRINTF : |%+10d|\n", -64);
	ft_printf("31) Mon PRINTF  : |%+10d|\n", -64);
	printf("32) Vrai PRINTF : |%+.10d|\n", -64);
	ft_printf("32) Mon PRINTF  : |%+.10d|\n", -64);
	printf("33) Vrai PRINTF : |%2d|\n", -20);
	ft_printf("33) Mon PRINTF  : |%2d|\n", -20);
	printf("34) Vrai PRINTF : |%.2d|\n", -20);
	ft_printf("34) Mon PRINTF  : |%.2d|\n", -20);
	printf("35) Vrai PRINTF : |%2d|\n", -1);
	ft_printf("35) Mon PRINTF  : |%2d|\n", -1);
	printf("36) Vrai PRINTF : |%.2d|\n", -1);
	ft_printf("36) Mon PRINTF  : |%.2d|\n", -1);
	printf("37) Vrai PRINTF : |%-10d|\n", -80);
	ft_printf("37) Mon PRINTF  : |%-10d|\n", -80);
	printf("38) Vrai PRINTF : |%-.10d|\n", -80);
	ft_printf("38) Mon PRINTF  : |%-.10d|\n", -80);
	printf("39) Vrai PRINTF : |%06d|\n", 35);
	ft_printf("39) Mon PRINTF  : |%06d|\n", 35);
	printf("40) Vrai PRINTF : |%06d|\n", -35);
	ft_printf("40) Mon PRINTF  : |%06d|\n", -35);
//	printf("41) Vrai PRINTF : |%-+10d|\n", -40);
//	ft_printf("41) Mon PRINTF  : |%-+10d|\n", -40);
//	printf("42) Vrai PRINTF : |%+-10d|\n", -40);
//	ft_printf("42) Mon PRINTF  : |%+-10d|\n", -40);
	printf("43) Vrai PRINTF : |%05.3d|\n", 5);
	ft_printf("43) Mon PRINTF  : |%05.3d|\n", 5);
	printf("44) Vrai PRINTF : |%03.5d|\n", 5);
	ft_printf("44) Mon PRINTF  : |%03.5d|\n", 5);
	printf("45) Vrai PRINTF : |%05.3d|\n", -5);
	ft_printf("45) Mon PRINTF  : |%05.3d|\n", -5);
	printf("46) Vrai PRINTF : |%03.5d|\n", -5);
	ft_printf("46) Mon PRINTF  : |%03.5d|\n", -5);
	printf("47) Vrai PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
	ft_printf("47) Mon PRINTF  : |%d| |%d|\n", INT_MAX, INT_MIN);
	printf("48) Vrai PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
	ft_printf("48) Mon PRINTF  : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
	printf("49) Vrai PRINTF : |%.d|\n", 0);
	ft_printf("49) Mon PRINTF  : |%.d|\n", 0);
	printf("50) Vrai PRINTF : |%.d|\n", 100);
	ft_printf("50) Mon PRINTF  : |%.d|\n", 100);


	ft_printf("--------------------%%x--------------------\n");		//29/29
	printf("01) Vrai PRINTF : |%x|\n", 34);
	ft_printf("01) Mon PRINTF  : |%x|\n", 34);
	printf("02) Vrai PRINTF : |%x|\n", -34);
	ft_printf("02) Mon PRINTF  : |%x|\n", -34);
	printf("03) Vrai PRINTF : |%-x|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-x|\n", 50);
	printf("04) Vrai PRINTF : |%10x|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10x|\n", 90);
	printf("05) Vrai PRINTF : |%.10x|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10x|\n", 90);
	printf("06) Vrai PRINTF : |%15x|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15x|\n", -100);
	printf("07) Vrai PRINTF : |%.15x|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15x|\n", -100);
	printf("08) Vrai PRINTF : |%10.5x|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5x|\n", 52);
	printf("09) Vrai PRINTF : |%5.10x|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10x|\n", 52);
	printf("10) Vrai PRINTF : |%20.15x|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15x|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20x|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20x|\n", -100000);
	printf("12) Vrai PRINTF : |%-10x|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10x|\n", 144);
	printf("13) Vrai PRINTF : |%-.10x|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10x|\n", 144);
	printf("14) Vrai PRINTF : |%-20x|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20x|\n", -20000000);
	printf("15) Vrai PRINTF : |%08x|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08x|\n", 64);
	printf("16) Vrai PRINTF : |%03.4x|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4x|\n", 10);
//	printf("17) Vrai PRINTF : |%#x|\n", 34);
//	ft_printf("17) Mon PRINTF  : |%#x|\n", 34);
//	printf("18) Vrai PRINTF : |%#.5x|\n", 34);
//	ft_printf("18) Mon PRINTF  : |%#.5x|\n", 34);
//	printf("19) Vrai PRINTF : |%#5x|\n", 86);
//	ft_printf("19) Mon PRINTF  : |%#5x|\n", 86);
//	printf("20) Vrai PRINTF : |%#10.5x|\n", 70);
//	ft_printf("20) Mon PRINTF  : |%#10.5x|\n", 70);
//	printf("21) Vrai PRINTF : |%#x|\n", 0);
//	ft_printf("21) Mon PRINTF  : |%#x|\n", 0);
//	printf("22) Vrai PRINTF : |%#.x|\n", 0);
//	ft_printf("22) Mon PRINTF  : |%#.x|\n", 0);
	printf("23) Vrai PRINTF : |%.x|\n", 0);
	ft_printf("23) Mon PRINTF  : |%.x|\n", 0);
	printf("24) Vrai PRINTF : |%.x|\n", 88);
	ft_printf("24) Mon PRINTF  : |%.x|\n", 88);
//	printf("25) Vrai PRINTF : |%#.x|\n", 88);
//	ft_printf("25) Mon PRINTF  : |%#.x|\n", 88);
	printf("26) Vrai PRINTF : |%x|\n", UINT_MAX);
	ft_printf("26) Mon PRINT   : |%x|\n", UINT_MAX);
//	printf("27) Vrai PRINTF : |%#x|\n", UINT_MAX);
//	ft_printf("27) Mon PRINTF  : |%#x|\n", UINT_MAX);
//	printf("28) Vrai PRINTF : |%#x| |%#x|\n", (unsigned int)-1, UINT_MAX + 1);
//	ft_printf("28) Mon PRINTF  : |%#x| |%#x|\n", (unsigned int)-1, UINT_MAX + 1);
	printf("29) Vrai PRINTF : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("29) Mon PRINTF  : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);


	ft_printf("--------------------%%X--------------------\n");
	printf("01) Vrai PRINTF : |%X|\n", 34);
	ft_printf("01) Mon PRINTF  : |%X|\n", 34);
	printf("02) Vrai PRINTF : |%X|\n", -34);
	ft_printf("02) Mon PRINTF  : |%X|\n", -34);
	printf("03) Vrai PRINTF : |%-X|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-X|\n", 50);
	printf("04) Vrai PRINTF : |%10X|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10X|\n", 90);
	printf("05) Vrai PRINTF : |%.10X|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10X|\n", 90);
	printf("06) Vrai PRINTF : |%15X|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15X|\n", -100);
	printf("07) Vrai PRINTF : |%.15X|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15X|\n", -100);
	printf("08) Vrai PRINTF : |%10.5X|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5X|\n", 52);
	printf("09) Vrai PRINTF : |%5.10X|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10X|\n", 52);
	printf("10) Vrai PRINTF : |%20.15X|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15X|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20X|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20X|\n", -100000);
	printf("12) Vrai PRINTF : |%-10X|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10X|\n", 144);
	printf("13) Vrai PRINTF : |%-.10X|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10X|\n", 144);
	printf("14) Vrai PRINTF : |%-20X|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20X|\n", -20000000);
	printf("15) Vrai PRINTF : |%08X|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08X|\n", 64);
	printf("16) Vrai PRINTF : |%03.4X|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4X|\n", 10);
//	printf("17) Vrai PRINTF : |%#X|\n", 34);
//	ft_printf("17) Mon PRINTF  : |%#X|\n", 34);
//	printf("18) Vrai PRINTF : |%#.5X|\n", 34);
//	ft_printf("18) Mon PRINTF  : |%#.5X|\n", 34);
//	printf("19) Vrai PRINTF : |%#5X|\n", 86);
//	ft_printf("19) Mon PRINTF  : |%#5X|\n", 86);
//	printf("20) Vrai PRINTF : |%#10.5X|\n", 70);
//	ft_printf("20) Mon PRINTF  : |%#10.5X|\n", 70);
//	printf("21) Vrai PRINTF : |%#X|\n", 0);
//	ft_printf("21) Mon PRINTF  : |%#X|\n", 0);
//	printf("22) Vrai PRINTF : |%#.X|\n", 0);
//	ft_printf("22) Mon PRINTF  : |%#.X|\n", 0);
	printf("23) Vrai PRINTF : |%.X|\n", 0);
	ft_printf("23) Mon PRINTF  : |%.X|\n", 0);
	printf("24) Vrai PRINTF : |%.X|\n", 88);
	ft_printf("24) Mon PRINTF  : |%.X|\n", 88);
//	printf("25) Vrai PRINTF : |%#.X|\n", 88);
//	ft_printf("25) Mon PRINTF  : |%#.X|\n", 88);
	printf("26) Vrai PRINTF : |%X|\n", UINT_MAX);
	ft_printf("26) Mon PRINT   : |%X|\n", UINT_MAX);
//	printf("27) Vrai PRINTF : |%#X|\n", UINT_MAX);
//	ft_printf("27) Mon PRINTF  : |%#X|\n", UINT_MAX);
//	printf("28) Vrai PRINTF : |%#X| |%#X|\n", (unsigned int)-1, UINT_MAX + 1);
//	ft_printf("28) Mon PRINTF  : |%#X| |%#X|\n", (unsigned int)-1, UINT_MAX + 1);

	ft_printf("--------------------%%u--------------------\n");		//19/20
	printf("01) Vrai PRINTF : |%u|\n", 34);
	ft_printf("01) Mon PRINTF  : |%u|\n", 34);
	printf("02) Vrai PRINTF : |%u|\n", -34);
	ft_printf("02) Mon PRINTF  : |%u|\n", -34);
	printf("03) Vrai PRINTF : |%-u|\n", 50);
	ft_printf("03) Mon PRINTF  : |%-u|\n", 50);
	printf("04) Vrai PRINTF : |%10u|\n", 90);
	ft_printf("04) Mon PRINTF  : |%10u|\n", 90);
	printf("05) Vrai PRINTF : |%.10u|\n", 90);
	ft_printf("05) Mon PRINTF  : |%.10u|\n", 90);
	printf("06) Vrai PRINTF : |%15u|\n", -100);
	ft_printf("06) Mon PRINTF  : |%15u|\n", -100);
	printf("07) Vrai PRINTF : |%.15u|\n", -100);
	ft_printf("07) Mon PRINTF  : |%.15u|\n", -100);
	printf("08) Vrai PRINTF : |%10.5u|\n", 52);
	ft_printf("08) Mon PRINTF  : |%10.5u|\n", 52);
	printf("09) Vrai PRINTF : |%5.10u|\n", 52);
	ft_printf("09) Mon PRINTF  : |%5.10u|\n", 52);
	printf("10) Vrai PRINTF : |%20.15u|\n", -100000);
	ft_printf("10) Mon PRINTF  : |%20.15u|\n", -100000);
	printf("11) Vrai PRINTF : |%15.20u|\n", -100000);
	ft_printf("11) Mon PRINTF  : |%15.20u|\n", -100000);
	printf("12) Vrai PRINTF : |%-10u|\n", 144);
	ft_printf("12) Mon PRINTF  : |%-10u|\n", 144);
	printf("13) Vrai PRINTF : |%-.10u|\n", 144);
	ft_printf("13) Mon PRINTF  : |%-.10u|\n", 144);
	printf("14) Vrai PRINTF : |%-20u|\n", -20000000);
	ft_printf("14) Mon PRINTF  : |%-20u|\n", -20000000);
	printf("15) Vrai PRINTF : |%08u|\n", 64);
	ft_printf("15) Mon PRINTF  : |%08u|\n", 64);
	printf("16) Vrai PRINTF : |%03.4u|\n", 10);
	ft_printf("16) Mon PRINTF  : |%03.4u|\n", 10);
	printf("17) Vrai PRINTF : |%u|\n", 0);
	ft_printf("17) Mon PRINTF  : |%u|\n", 0);
	printf("18) Vrai PRINTF : |%.u|\n", 0);
	ft_printf("18) Mon PRINTF  : |%.u|\n", 0);
	printf("19) Vrai PRINTF : |%10u|\n", 0);
	ft_printf("19) Mon PRINTF  : |%10u|\n", 0);
	printf("20) Vrai PRINTF : |%.u|\n", 88);
	ft_printf("20) Mon PRINTF  : |%.u|\n", 88);
	printf("21) Vrai PRINTF : |%u|\n", UINT_MAX);
	ft_printf("21) Mon PRINTF  : |%u|\n", UINT_MAX);
	printf("22) Vrai PRINTF : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("22) Mon PRINTF  : |%u| |%u|\n", (unsigned int)-1, UINT_MAX + 1);
	printf("%x\n", 4294967299);
	ft_printf("%x\n", 4294967299);
	return (0);
}
