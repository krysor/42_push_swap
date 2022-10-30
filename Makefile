SRCS	= input.c ft_atopi.c

OBJS	= ${SRCS:.c=.o}

NAME	= push_swap

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			${MAKE} -C libft
			${MAKE} bonus -C libft
			#${MAKE} -C lists
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a #lists/lists.a

all:		${NAME}

bonus:		all

clean:
			${RM} ${OBJS}
			$(MAKE) clean -C libft

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all bonus clean fclean re