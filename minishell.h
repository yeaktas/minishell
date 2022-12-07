#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>

#define command 2
#define flag 4
#define arg 8
typedef struct s_token
{
	char	*input;
	int		type;
}	t_token;

typedef struct s_big_hole
{
	t_token	token;
}	t_big_hole;

int	ft_lexer(char *inp);
int	token_typing(char *str);

int	if_command(char *str);
int	word_count(char *str);

#endif