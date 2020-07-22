
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef struct		s_flags
{
	int     var_type_met;
	int		minus_met;
	int		zero_met;
	int		cur_width;
	int		star_met;
	int     dot_met;
}			t_flags;

int 		ft_printf(const char *s, ...);
int 		ft_read_str(const char *s, va_list av);
int 		var_type_deal(int c, t_flags flags, va_list av);
int 		flag_type_read(const char *s, int i, t_flags *flags, va_list av);
int 		var_type(int c);
t_flags		set_dflt_flags(void);
t_flags		flag_digit(char c, t_flags flags);
int			flag_dot(const char *s, int i, t_flags *flags, va_list av);
t_flags		flag_width(t_flags flags, va_list av);
t_flags		flag_minus(t_flags flags);
int 		ft_width_deal(int width, int str_len, int zero_flag);
int 		ft_case_s(char *s, t_flags flags);
int 		ft_put_s(char *s, t_flags flags, size_t len);
int 		ft_case_c(char c, t_flags flags);
int 		ft_case_prc(t_flags flags);
int 		ft_case_d(int nbr, t_flags flags);
int         ft_flag_deal_d(char *nbr_str, int tmp, t_flags flags);
int         ft_put_d(char *nbr_str, int tmp, t_flags flags, size_t len);
int 		ft_case_x(unsigned int nbr, int lower, t_flags flags);
int         ft_flag_deal_x(char *x, t_flags flags);
int         ft_put_x(char *x, t_flags flags, size_t len);
char		*ft_itoa_base(unsigned long long n, int base, int flag);
int         ft_uxX_len(unsigned long long numb, int base);
int 		ft_case_p(unsigned long long nbr, t_flags flags);
int 		ft_put_p(char *str, t_flags flags, size_t len);
int			ft_case_u(unsigned int nbr, t_flags flags);
int         ft_flag_deal_u(char *nbr_str, t_flags flags);
int      	ft_put_u(char *nbr_str, t_flags flags, size_t len);

#endif