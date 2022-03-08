# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchromos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 15:11:29 by cchromos          #+#    #+#              #
#    Updated: 2020/12/21 15:14:22 by cchromos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c	work_with_struct/fill_struct.c	work_with_struct/find_argc.c	work_with_struct/format_big_x.c	work_with_struct/format_c.c	work_with_struct/format_d_or_i.c	work_with_struct/format_p.c	work_with_struct/format_u.c	work_with_struct/format_s.c	work_with_struct/format_x.c	work_with_struct/negativ_number.c	work_with_struct/putnbr_base.c	work_with_struct/utils.c	work_with_struct/utils_d_or_i.c	work_with_struct/utils_d_or_i_is_zero.c

OBJS = $(SRCS:%.c=%.o)

CC	= gcc

RM	= rm -f

FLAGS = -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS} ft_printf.h work_with_struct/work_with_struct.h libft/libft.h
			cd libft && make && mv libftprintf.a ../
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

clean:
			${RM} ${OBJS}
			cd libft && ${RM} *.o

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}
			
			
.PHONY:		all clean fclean re
