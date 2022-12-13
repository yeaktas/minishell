#include "minishell.h"

t_list	*token_create(char *string, int type)
{
	t_token *t_tok;
	t_list  *token;

	t_tok = malloc(sizeof(t_token));
	if (t_tok == NULL)
		return (NULL);
	t_tok->flags = type;
	t_tok->str = string;
	token = ft_lstnew(t_tok);
	if (token == NULL)
		return (NULL);
	token->next = NULL;
	return (token);
}

int	lexer_token_bracket(char *str, int *i, t_list **l_token)
{
	t_list  *token;
	char    *token_str;

	if(str[*i] == '(' || str[*i] == ')')
	{
		token_str = ft_substr(str, *i, 1);
		if(token_str == NULL)
			return(ERROR);// error ciktisi icin printf yaziliacak
		if(str[*i] == '(')
			token = token_create(str, TOK_BRACKET_OPEN);
		else
			token = token_create(str, TOK_BRACKET_CLOSE);
		if (token == NULL)  // su ifte niye hata varrrrrr
		{
			free(token_str);
			return(ERROR); //error ciktisi icin printf yazilicak
		}
		ft_lstadd_back(l_token, token); // l_token = token listemizdir, token listemizin sonuna tokenimizi yolluyoruz!!
	}
	return (0);
}

t_token	*token_content(t_list *token)
{
	return ((t_token *)token->content);
}

static int	other_len(char *chr)
{
	if (*chr == '(' || *chr == ')')
		return (1);
	else if (*chr == '<' && *(chr + 1) != '<')// kontrol edilcek
		return (1);
	else if (*chr == '<' && *(chr + 1) == '<')
		return (2);
	else if (*chr == '>' && *(chr + 1) != '>')
		return (1);
	else if (*chr == '>' && *(chr + 1) == '>')
		return (2);
	else if (*chr == '|' && *(chr + 1) != '|')
		return (1);
	else if (*chr == '|' && *(chr + 1) == '|')
		return (2);
	else if (*chr == '&' && *(chr + 1) == '&')
		return (2);
	return (0);
}
int	lexer_token_quote(char *str, int *i, t_list **l_token)
{
	t_list  *token;
	char	*token_str;
	int		len;

	len = quote_len(&str[*i]);
	if (len == ERROR)
		return (ERROR);
	if (len > 0)
	{
		token_str = ft_substr(str, *i + 1, len - 2);  //quote yi almamak icin i + 1 yaptik len-2 nin biri quote icin digeri null
		if (token_str == NULL)
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		if (str[*i] == '\'')
			token = token_create(token_str, TOK_TEXT | TOK_S_QUOTE);
		else
			token = token_create(token_str, TOK_TEXT | TOK_D_QUOTE);
		if (token == NULL)
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		ft_lstadd_back(l_token, token);
		if (!ft_strchr(WHITESPACE, str[*i]) && other_len(&str[*i]) == 0)
			token_content(token)->flags |= TOK_CONNECTED;
	}
	return (0);
}