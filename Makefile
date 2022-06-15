# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvander- <jvander-@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:30:54 by jvander-          #+#    #+#              #
#    Updated: 2021/10/22 10:43:20 by jvander-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	=	server
NAME_CLIENT	=	client
CC		=	gcc
INCLUDES = -I./includes/
FLAGS	=	-Wall -Werror -Wextra $(INCLUDES)
PRINTF	=	./ft_printf
LIB_PRINTF	=	$(PRINTF)/ft_printf.a


SRCS_CLIENT	=	client.c \
				utils.c \

SRCS_SERVER	=	server.c \

OBJS_CLIENT		=	$(SRCS_CLIENT:.c=.o)

OBJS_SERVER		=	$(SRCS_SERVER:.c=.o)

all:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):	$(OBJS_SERVER)
				$(MAKE) -C $(PRINTF)
				$(CC) $(FLAGS) $(OBJS_SERVER) -o $(NAME_SERVER) $(LIB_PRINTF)

$(NAME_CLIENT):	$(OBJS_CLIENT)
				$(CC) $(FLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT) $(LIB_PRINTF)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(MAKE) clean -C $(PRINTF)
		rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean:	clean
		$(MAKE) fclean -C $(PRINTF)
		rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re