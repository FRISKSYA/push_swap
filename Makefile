# Makefile for push_swap project

# Variables
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCS_DIR = ./srcs
PRINTF_DIR = ./utils/ft_printf
LIBFT_DIR = ./utils/libft

# Source files
SRCS_FILES = fill_stacks.c free_str_arr.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lsthead.c ft_lstlast.c ft_lstnew.c ft_lstsize.c\
			 get_cost_to_head.c get_target_node_a.c get_target_node_b.c move_node_min_ops.c proc_sort_begin.c proc_sort_end.c\
			 push_nodes.c push_swap.c reverse_rotate_stacks.c rotate_stacks.c sort_stacks.c swap_nodes.c validate_args.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

# Object files
OBJS = $(SRCS:.c=.o)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# Dependencies
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re
