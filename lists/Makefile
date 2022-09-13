SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		  ft_lstadd_back.c ft_lstdelfirst.c ft_lstclear.c ft_putlst_fd.c

OBJS	= ${SRCS:.c=.o}

NAME	= lists.a

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			ar r ${NAME} ${OBJS}			

all:		${NAME}

bonus:		${BOBJS}
			@ar r ${NAME} ${BOBJS}
			@echo "relinking bonus finished"

clean:
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus clean fclean re