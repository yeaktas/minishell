#include "minishell.h"

int lexer_token_pipe(char *str, int *i, t_list **l_token)
{
	t_list	*token;
	char	*new_str;
	if (str[*i] == '|')
	{
		new_str = ft_substr(str, *i, 1);
		if (new_str == NULL)
			;
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM))); // printf(error);
		token = token_create(new_str, TOK_PIPE);
		if (token == NULL)
		{
			free(new_str);
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM))); // ERROR MESSAGE EKLE;
		}
		ft_lstadd_back(l_token, token); // listenın sonuna ekledik;
		(*i)++;
	}
	return (0);
}

int	lexer_token_redir(char *str, int *i, t_list **l_token)
{
	t_list	*token;
	char	*token_str;

	int(len) = 0;
	// while (ft_isdigit(str[*i + len]))
	// 	len++;
	if (str[*i + len] == '<' || str[*i + len] == '>')
	{
		if (str[*i + len] == str[*i + len + 1])
			len++;
		len++;
		token_str = ft_substr(str, *i, len);
		if (token_str == NULL)
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		token = token_create(token_str, TOK_REDIR);
		if (token == NULL)
		{
			free(token_str);
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		}
		ft_lstadd_back(l_token, token);
		*i += len;
	}
	return (0);
}

int	lexer_token_bracket(char *str, int *i, t_list **l_token)
{
	t_list	*token;
	char	*token_str;

	if (str[*i] == '(' || str[*i] == ')')
	{
		token_str = ft_substr(str, *i, 1);
		if (token_str == NULL)
			return (ERROR); // error ciktisi icin printf yaziliacak
		if (str[*i] == '(')
			token = token_create(str, TOK_BRACKET_OPEN);
		else
			token = token_create(str, TOK_BRACKET_CLOSE);
		if (token == NULL) // su ifte niye hata varrrrrr
		{
			free(token_str);
			return (ERROR); // error ciktisi icin printf yazilicak
		}
		ft_lstadd_back(l_token, token); // l_token = token listemizdir,token listemizin sonuna tokenimizi yolluyoruz !!
	}
	return (0);
}

