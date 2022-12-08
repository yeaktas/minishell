#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>

#define COMMAND 2
#define FLAG 4
#define ARG 8
#define SUCCESS -1
#define FAILURE -2
#define EMPTY -3

typedef struct s_token
{
	char			*name;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_big_hole
{
	char	**word;
	t_token	*token;
}	t_big_hole;

//minishell.c

//ultra_mega_split.c
int	quote_check(char *inp);

//lexer.c
int	ft_lexer(char *inp);

//utils.c
int	word_count(char *str);

#endif