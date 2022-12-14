#include "minishell.h"

int	syntax_brackets(t_list *l_token)
{
	int(count) = 0;
	while (l_token)
	{
		if (token_content(l_token)->flags & TOK_BRACKET_OPEN)
		{
			count++;
			if (l_token->next
				&& token_content(l_token->next)->flags & TOK_BRACKET_CLOSE)
			{
				print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_EMPTY_BRACKET);
				return (ERROR);
			}
		}
		else if (token_content(l_token)->flags & TOK_BRACKET_CLOSE)
			count--;
		if (count < 0)
			return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_UNO_BRACKET));
		l_token = l_token->next;
	}
	if (count > 0)
		return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_UNC_BRACKET));
	return (0);
}

int	syntax_pipe(t_list *l_token)
{
	if (l_token && token_content(l_token)->flags & TOK_PIPE)//ilk tokene bakıyor burada ilk tokenimiz pipe olmaz;
		return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
	while (l_token)
	{
		if (token_content(l_token)->flags & TOK_PIPE)
		{
			if (l_token->next == NULL)//pipe dan sonra null gelemez
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
			else if (token_content(l_token)->flags
				& (TOK_BIN_OP | TOK_PIPE))//pipe dan sonra pipe gelemz ((BİN OP KONTROL ET ÖNEMLİ)) 
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
			else if (token_content(l_token->next)->flags & TOK_BRACKET_CLOSE)//pipe dan sonra tok braket gelemez;
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
		}
		if (token_content(l_token)->flags & TOK_BRACKET_OPEN)//parantez var mı
		{
			if (l_token->next && token_content(l_token->next)->flags & TOK_PIPE)//parantezin içerisinde pipe olmaz;
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_PIPE));
		}
		l_token = l_token->next;//diger tokene geçiyor;
	}
	return(0);
}

