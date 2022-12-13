#include "minishell.h"

t_big_hole	*big_ass;

void	my_print()
{
	
}
int	lexer(char *inp)
{
	t_list	*l_token;
	int (i) = -1;

	while (inp[++i])
	{
		if (lexer_token_pipe(inp, &i, &l_token) == ERROR)
			break ;
		else if (lexer_token_quote(inp, &i, &l_token) == ERROR)
			break ;
		else if (lexer_token_text(inp, &i, &l_token) == ERROR)
			break ;
		else if (lexer_token_redir(inp, &i, &l_token) == ERROR)
			break ;
		else if (lexer_token_bracket(inp, &i, &l_token) == ERROR)
			break ;
		while (inp[i] && ft_strchr(WHITESPACE, inp[i]) != 0)
			i++;
	}
	return(0);
}
//quote -
//text -
//pipe +
//redir -
//bracket +
//whitspace +