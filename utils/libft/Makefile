NAME	=	libft.a
SRCS	=	ft_isalpha.c ft_isdigit.c ft_isascii.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c ft_atoi.c ft_strdup.c ft_isalnum.c ft_isprint.c ft_toupper.c ft_tolower.c\
			ft_strchr.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_strnstr.c ft_memcmp.c ft_strrchr.c ft_calloc.c ft_substr.c ft_strjoin.c  ft_split.c\
			ft_itoa.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c
OBJS	=	$(SRCS:.c=.o)
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME):	$(OBJS)
	ar rc $(NAME) $^
	ranlib $(NAME)

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 
fclean:	clean
	$(RM) $(NAME)

re: fclean bonus
