NAME = sorter

CC = gcc

CFLAGS = -Werror -Wall -Wextra -fsanitize=address

RM = rm -rf

SRCS = 	src/sorter_main.c\
		src/indexing.c\
		src/ops_push.c\
		src/ops_rotate.c\
		src/ops_swap.c\
		src/ops_reverse_rotate.c\
		src/radix_sort_impl.c\
		src/sort_manager.c\
		src/sort_helpers.c\
		libft/libft.a\

SRCS_BONUS = src_bonus/verifier_bonus.c\
			src_bonus/ops_push_bonus.c\
			src_bonus/ops_rotate_bonus.c\
			src_bonus/ops_swap_bonus.c\
			src_bonus/ops_reverse_rotate_bonus.c\
			src_bonus/verifier_utils_bonus.c\
			libft/libft.a\

$(NAME) :
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all

bonus : 
	make bonus -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o verifier