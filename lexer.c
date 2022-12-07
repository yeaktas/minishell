#include "minishell.h"

t_big_hole	*big_a$$;

int	token_typing(char *str)
{
	if (if_command(str))
		big_a$$[0].token.type = command;
	return (1);
}

int	ft_lexer(char *inp)
{
	int	wcount;

	wcount = word_count(inp);
	printf("%d", wcount);
	big_a$$ = malloc(sizeof(t_big_hole) * wcount);

	return(0);
}