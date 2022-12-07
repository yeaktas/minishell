NAME = minishell
LIBFT = libft
SRCS = $(wildcard *.c)

CFLAGS = -lreadline -L ~/goinfre/homebrew/opt/readline/lib -I ~/goinfre/homebrew/opt/readline/include -Wall -Werror -Wextra

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME) :
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft/libft.a $(NAME)
	$(CC) $(SRCS) libft.a $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean re fclean all