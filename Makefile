# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtweek <vtweek@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 02:19:11 by vtweek            #+#    #+#              #
#    Updated: 2020/07/23 02:19:15 by vtweek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
HEADER = include/ft_printf.h

SOURCE = srcs/ft_printf.c \
	srcs/ft_printf_d.c \
	srcs/ft_printf_x_i_base.c \
	srcs/ft_printf_s_c_prc.c \
	srcs/ft_printf_flags.c \
	srcs/ft_printf_u_p.c \

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

OBJECTS = $(SOURCE:%.c=%.o)

$(NAME):	$(OBJECTS)
	@$(MAKE) all -C ./libft
#	@$(MAKE) bonus -C ./libft
	@cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJECTS)

all:	$(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJECTS)

fclean:	clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re:	fclean all

bonus:	$(MAKE) all

.PHONY:	all clean fclean re bonus
