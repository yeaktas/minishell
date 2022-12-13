#include "minishell.h"

int lexer_token_pipe(char *str, int *i, t_list **l_token)
{
	t_list *token;
	char *new_str;
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
}
// t_liste lst_add_back yap;