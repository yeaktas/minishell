#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>

#define command 2
#define flag 4
#define arg 8
typedef struct s_token
{
	char	*name;
	int		type;
}	t_token;

typedef struct s_big_hole
{
	t_token	*token;
}	t_big_hole;

//minishell.c

//lexer.c
int	ft_lexer(char *inp);

//utils.c
int	word_count(char *str);

#endif