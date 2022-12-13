NAME = minishell
LIBFT = libft
SRCS = $(wildcard *.c)

CFLAGS = -lreadline -g -L /goinfre/homebrew/opt/readline/lib -I /goinfre/homebrew/opt/readline/include -Wall -Werror -Wextra

CC = gcc

RM = rm -f

all: $(NAME)
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft/libft.a $(NAME)

$(NAME):
	$(CC) $(SRCS) libft.a $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

libclean: fclean
	make clean -C $(LIBFT)

re: fclean $(NAME)

.PHONY: clean re fclean libclean all