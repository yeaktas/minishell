#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>

#define	CHAR_PIPE '|'
#define	CHAR_AMPERSAND '&'
#define	CHAR_QOUTE '\''
#define	CHAR_DQUOTE '\"'
#define	CHAR_SEMICOLON ';'
#define	CHAR_WHITESPACE ' '
#define	CHAR_ESCAPESEQUENCE '\\'
#define	CHAR_TAB '\t'
#define	CHAR_NEWLINE '\n'
#define	CHAR_GREATER '>'
#define	CHAR_LESSER '<'
#define	CHAR_NULL 0

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
	char	**env;
	t_token	*token;
}	t_big_hole;

//minishell.c

//ultra_mega_split.c

//lexer.c
int		ft_lexer(char *inp);
char	*take_quote(char *inp, char c, int quote);
char	*take_space(char *inp, int n);

//utils.c
int		word_count(char *str);
t_token	*token_new(void *content);
void	token_add_back(t_token **lst, t_token *new);

#endif