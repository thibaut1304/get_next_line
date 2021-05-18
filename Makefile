# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:00:38 by thhusser          #+#    #+#              #
#    Updated: 2020/11/05 14:00:38 by thhusser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libgnl.a

SRCS	=	get_next_line.c

OBJS	=	${SRCS:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

HEADER	=	-I ./

.c.o:
			@gcc ${CFLAGS} -c $< -o $(<:.c=.o) ${HEADER}

${NAME}:	${OBJS}
			@gcc $(FLAGS) -c $(SRCS)
			@ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:	
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
