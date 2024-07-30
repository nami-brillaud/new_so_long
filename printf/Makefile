# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 16:53:15 by nfujisak          #+#    #+#              #
#    Updated: 2024/06/26 16:26:45 by nfujisak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_base.c ft_csp.c ft_diux.c ft_helpers.c ft_printf.c

OBJS	= $(SRCS:.c=.o)

HEAD	= ft_printf.h

NAME	= libftprintf.a

LIBFT	= ../libft/libft.a

AR		= ar rc

RM		= rm -f

LIB 	= ranlib

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all		= ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

all: $(NAME)

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

.PHONY:	all bonus clean fclean re


