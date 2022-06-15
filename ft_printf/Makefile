# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 10:07:20 by jvander-          #+#    #+#              #
#    Updated: 2021/10/21 14:41:53 by jvander-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf.a

CC		=	gcc

HEADERS = 	ft_printf.h

FLAGS	=	-Wall -Werror -Wextra -I$(HEADERS)

SRC		=	ft_printf.c \
			ft_putchar.c \
			ft_putnbr_base.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_nb_len.c \
			ft_putnbr_base_u.c \
			ft_putnbr_base_ull.c \

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $?

OBJ		=	$(SRC:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
