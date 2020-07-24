# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 02:19:11 by vtweek            #+#    #+#              #
#    Updated: 2020/07/24 21:39:21 by vtweek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h

SOURCE = ft_printf.c \
	ft_printf_d.c \
	ft_printf_x_i_base.c \
	ft_printf_s_c_prc.c \
	ft_printf_flags.c \
	ft_printf_u_p.c \

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

OBJECTS = ft_printf.o \
	ft_printf_d.o \
	ft_printf_x_i_base.o \
	ft_printf_s_c_prc.o \
	ft_printf_flags.o \
	ft_printf_u_p.o \

$(NAME):	$(OBJECTS)
	$(MAKE) all -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJECTS)

all:	$(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re:	fclean all

bonus:	$(MAKE) all

.PHONY:	all clean fclean re bonus
