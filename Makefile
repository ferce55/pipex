NAME		=	pipex
SRCS		=	./srcs/utils.c ./srcs/pipex.c ./srcs/path_file_utils.c

CC			=	@gcc
CFLAGS		=	-g -fsanitize=address
RM			=	rm -rf


OBJS		=	$(SRCS:.c=.o)
LIBFT_DIR	=	libft/
LIBFT		=	${LIBFT_DIR}libft.a

$(NAME):	$(LIBFT) $(OBJS)
		@echo "---------Compiling Pipex----------"
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
		@echo "--------------DONE!!--------------"

$(LIBFT):
		@echo "---------Compiling Libft----------"
		@make -s -C $(LIBFT_DIR)
		@echo "--------------DONE!!--------------"

all:		${NAME}

clean:
		@echo "-------Cleaning Libft files-------"
		@make -s -C $(LIBFT_DIR) clean
		@echo "-------Cleaning Pipex files-------"
		@$(RM) $(OBJS)
		@echo "--------------DONE!!--------------"

fclean:	clean
		@echo "-------fCleaning Libft files------"
		@make -s -C $(LIBFT_DIR) fclean
		@echo "-------fCleaning Pipex files------"
		@$(RM) $(NAME)
		@echo "--------------DONE!!--------------"

re:		fclean all

.PHONY:	all fclean clean re