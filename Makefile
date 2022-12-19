# SRC_DIR = ./src
# OBJ_DIR = ./obj
# INC_DIR = ./inc

# SRC = $(wildcard $(SRC_DIR)/*.c)
# OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# NAME = minishell
# LIBFT = libft


# CFLAGS = -lreadline -g -L ~/goinfre/homebrew/opt/readline/lib -I ~/goinfre/homebrew/opt/readline/include -Wall -Werror -Wextra

# CC = gcc

# RM = rm -f

# $(NAME): all
# 	$(CC) $(SRCS) libft.a $(CFLAGS) -o $(NAME)

# all:
# 	make -C $(LIBFT)
# 	cp libft/libft.a .
# 	mv libft/libft.a $(NAME)


# clean:
# 	$(RM) $(OBJS)

# fclean: clean
# 	$(RM) $(NAME)

# libclean: fclean
# 	make clean -C $(LIBFT)

# re: fclean $(NAME)

# .PHONY: clean re fclean libclean all

# SRC_DIR = ./src
# OBJ_DIR = ./obj
# INC_DIR = ./inc
# LIBFT_DIR = ./src/libft

# SRC = $(wildcard $(SRC_DIR)/*.c)
# OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# CFLAGS = -g -L ~/goinfre/homebrew/opt/readline/lib -I ~/goinfre/homebrew/opt/readline/include/readline/ -Wall -Werror -Wextra

# NAME = minishell

# all: $(OBJ_DIR) $(NAME)
# 	make -C $(LIBFT)
# 	cp $(LIBFT_DIR)/libft.a .
# 	mv obj/libft.a $(NAME)

# $(OBJ_DIR):
# 	mkdir -p $@

# $(NAME): $(OBJ)
# 	gcc -o $@ $(OBJ)

# $(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c
# 	$(CC) -c $(CFLAGS) -I $(INC_DIR) $< -o $@

# run: all
# 	@echo "\033[92m \033[3mRunning \033[0m \033[0m"
# 	@./$(NAME)

# clean: 
# 	rm -rf obj

# fclean: clean
# 	rm -rf $(NAME)

# re: fclean all

NAME        := minishell

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -O2

CPPFLAGS    := -I./inc -I./lib/libft/inc
DEPFLAGS     = -MT $@ -MMD -MP -MF $(DDIR)/$*.d

LDFLAGS     := /lib/libft
LDLIBS      := -lft -lreadline

VPATH       := src/ src/lexer/ 
SRCS        := minishell.c
SRCS        += lexer.c lexer_token_get.c lexer_check.c lexer_token_text.c

ODIR        := obj
OBJS        := $(SRCS:%.c=$(ODIR)/%.o)

DDIR        := $(ODIR)/.deps
DEPS        := $(SRCS:%.c=$(DDIR)/%.d)

# **************************************************************************** #
#	SYSTEM SPECIFIC SETTINGS							   					   #
# **************************************************************************** #

# **************************************************************************** #
#   RULES                                                                      #
# **************************************************************************** #

.PHONY: all clean fclean re test

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)

$(ODIR)/%.o: %.c $(DDIR)/%.d | $(ODIR) $(DDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(DEPFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $@

$(DDIR):
	mkdir -p $@

%.a:
	$(MAKE) -C $(dir $@)

all: $(NAME)

clean:
	$(MAKE) -C libft fclean
	$(RM) -r $(DDIR) $(ODIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(DEPS):
include $(wildcard $(DEPS))
