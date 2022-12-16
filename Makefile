SRCS	= main.c ft_parse.c ft_atopi.c ft_isdup.c ft_solve.c ft_lstdup.c \
			ft_issorted.c ft_contdup.c ft_push.c ft_swap.c \
				ft_rotate.c ft_revrotate.c ft_lstinit.c ft_strempty.c \
					ft_putbest.c ft_get_nb.c

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