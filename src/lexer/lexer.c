#include "minishell.h"

t_big_hole	*big_ass;

t_list	*lexer_token_get(char *input);

t_list	*lexer(char *input)
{
	t_list	*l_token;

	l_token = lexer_token_get(input);
	if(l_token == NULL)
		return (NULL);
	return (NULL);
}

t_list	*lexer_token_get(char *input)
{
	t_list	*l_token;
	int (i) = -1;

	while (input[++i])
	{
		if (lexer_token_pipe(input, &i, &l_token) == ERROR)
			break ;
		else if (lexer_token_quote(input, &i, &l_token) == ERROR)
			break ;
		else if (lexer_token_text(input, &i, &l_token) == ERROR)
			break ;
		else if (lexer_token_redir(input, &i, &l_token) == ERROR)
			break ;
		else if (lexer_token_bracket(input, &i, &l_token) == ERROR)
			break ;
		while (input[i] && ft_strchr(WHITESPACE, input[i]) != 0)
			i++;
	}
	if (input[i] != '\0')
		ft_lstclear(&l_token, c_token_destroy);
	return (l_token);
}
//quote emircan
//bracket emircan
//redir emircan
//text aktas
//pipe ekaraogl
//whitspace tacikgoz

