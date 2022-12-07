NAME = minishell

SRCS = $(wildcard *.c)

CFLAGS = -lreadline -L ~/goinfre/homebrew/opt/readline/lib -I ~/goinfre/homebrew/opt/readline/include -Wall -Werror -Wextra

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME) :
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean re fclean all