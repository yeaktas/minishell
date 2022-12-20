#include "minishell.h"

t_big_hole	*big_ass;

t_list	*lexer_token_get(char *input);
static int	redir_mark_files(t_list *l_token);

t_list	*lexer(char *input)
{
	t_list	*l_token;

	l_token = lexer_token_get(input);
	if(l_token == NULL)
		return (NULL);
	else if (lexer_syntax_check(l_token) == ERROR)
	{
		ft_lstclear(&l_token, c_token_destroy);
		return (NULL);
	}
	else if (redir_mark_files(l_token) == ERROR)
	return (l_token);
}

t_list	*lexer_token_get(char *input)
{
	t_list	*l_token;
	int (i) = -1;

	l_token = NULL;
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

//buna bakilacak
static int	redir_mark_files(t_list *l_token)
{
	while (l_token)
	{
		if (token_content(l_token)->flags & TOK_REDIR)
		{
			if (l_token->next == NULL
				|| !(token_content(l_token->next)->flags & TOK_TEXT))
			{
				print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_REDIR);
				return (ERROR);
			}
			l_token = l_token->next;
			token_content(l_token)->flags |= TOK_REDIR_FILE;
			while (token_content(l_token)->flags & TOK_CONNECTED)
			{
				token_content(l_token->next)->flags |= TOK_REDIR_FILE;
				l_token = l_token->next;
			}
		}
		l_token = l_token->next;
	}
	return (0);
}