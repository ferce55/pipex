NAME		=	pipex
SRCS		=	./srcs/utils.c ./srcs/pipex.c ./srcs/file_utils.c

CC			=	gcc
CFLAGS		=	
RM			=	rm -rf


OBJS		=	$(SRCS:.c=.o)
LIBFT_DIR	=	libft/
LIBFT		=	${LIBFT_DIR}libft.a

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

all:		${NAME}

clean:
		make -C $(LIBFT_DIR) clean
		$(RM) $(OBJS)

fclean:	clean
		make -C $(LIBFT_DIR) fclean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all fclean clean re