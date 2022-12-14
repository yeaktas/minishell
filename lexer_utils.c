#include "minishell.h"

int quote_len(char *str)
{
	char quote;
	int(i) = 0;

	if (str == NULL)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	if (!ft_strchr(QUOTE, str[0]))
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	quote = str[0];
	while (str[++i])
	{
		if (str[i] == quote)
			break;
	}
	if (str[i] != quote)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	return (i + 1);
}
//!!!!@@!@!#!!!!Neden i+1?????
// str != null
// strchr str[0] = tirnak olacak
// charin icine tirnak atilcak
// ikinci tirnagi gordugunde break atip index al
// indexdeki harf tirnak degilse error
// return i+1;

int	other_len(char *chr) // bu fonksiyonun bir kismi sanirim bonus (yaktas)
{
	if (*chr == '(' || *chr == ')')
		return (1);
	else if (*chr == '<' && *(chr + 1) != '<') // kontrol edilcek
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

t_token *list_to_token(t_list *l_token)
{
	return ((t_token *)l_token->content);
}

t_list	*token_create(char *string, int type) //disaridan token tipini(text, |,<,>) ve makrosunu aliyor.
{
	t_token *t_tok;
	t_list *token;

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

void	c_token_destroy(void *c_token)
{
	free(((t_token *)c_token)->str);
	((t_token *)c_token)->str = NULL;
	free(c_token);
}