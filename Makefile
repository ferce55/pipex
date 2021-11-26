NAME		=	pipex
SRCS		=	./srcs/utils.c ./srcs/pipex.c ./srcs/path_file_utils.c

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
		@echo "-------Cleaning Libft files-------"
		make -C $(LIBFT_DIR) clean
		@echo "-------Cleaning Pipex files-------"
		$(RM) $(OBJS)
		@echo "--------------DONE!!--------------"

fclean:	clean
		@echo "-------Cleaning Libft files-------"
		make -C $(LIBFT_DIR) fclean
		@echo "-------Cleaning Pipex files-------"
		$(RM) $(NAME)
		@echo "--------------DONE!!--------------"

re:		fclean all

.PHONY:	all fclean clean re