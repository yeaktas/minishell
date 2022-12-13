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