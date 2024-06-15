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
SRCS = $(wildcard $(SRCS_DIR)/*.c)

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
