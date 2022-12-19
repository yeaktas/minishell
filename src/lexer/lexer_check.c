#include "minishell.h"

static int	syntax_bin_op(t_list *l_token);
static int	syntax_brackets(t_list *l_token);
static int	syntax_pipe(t_list *l_token);
static int	syntax_missing_op(t_list *l_token);

int lexer_syntax_check(t_list *l_token)
{
	if (syntax_brackets(l_token) == ERROR)
		return(ERROR);
	if (syntax_pipe(l_token) == ERROR)
		return(ERROR);
	if(syntax_missing_op(l_token) == ERROR)
		return(ERROR);
	if(syntax_bin_op(l_token) == ERROR)
		return(ERROR);
	return(0);
}

static int	syntax_bin_op(t_list *l_token)
{
	if (l_token && token_content(l_token)->flags & TOK_BIN_OP)
		return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
	while (l_token)
	{
		if (token_content(l_token)->flags & TOK_BIN_OP)
		{
			if (l_token->next == NULL)
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
			else if (token_content(l_token->next)->flags
				& (TOK_BIN_OP | TOK_PIPE))
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
			else if (token_content(l_token->next)->flags & TOK_BRACKET_CLOSE)
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
		}
		if (token_content(l_token)->flags & TOK_BRACKET_OPEN)
		{
			if (l_token->next
				&& token_content(l_token->next)->flags & TOK_BIN_OP)
				return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_LIST));
		}
		l_token = l_token->next;
	}
	return (0);
}

static int	syntax_brackets(t_list *l_token)
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

static int	syntax_pipe(t_list *l_token)
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

static int	syntax_missing_op(t_list *l_token)
{
	while (l_token)
	{
		if (token_content(l_token)->flags & TOK_BRACKET_CLOSE
			&& l_token->next
			&& token_content(l_token->next)->flags & TOK_BRACKET_OPEN)
			return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_MISS_OP));
		// else if (token_content(l_token)->flags & TOK_BRACKET_OPEN
			// && token_is_cmd(l_token->next))
			// return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_MISS_OP));
		// else if (token_is_cmd(l_token)
			// && l_token->next
			// && token_content(l_token->next)->flags & TOK_BRACKET_OPEN)
			// return (print_error(SHELL_NAME, ERR_SYNTAX, NULL, ERR_MISS_OP));
		l_token = l_token->next;
	}
	return (0);
}
