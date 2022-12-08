#include "minishell.h"

t_big_hole	*big_a$$;

void	my_print()
{
	int i;

	i = 0;
	printf("%s ", big_a$$->token[i].name);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
}

t_token take_quote(char *inp, char c, int quote)
{
	int	i;
	int	j;
	t_token tmp;

	j = 0;
	i = quote;
	while (inp[++i] && ++j)
	{
		if (inp[i] == c)
			break;
	}
	tmp.name = malloc(sizeof(char) * j);
	tmp.name[j] = '\0';
	while (quote < j--)
	{
		if(!(tmp.name[j] == c))
			tmp.name[j] = inp[quote + j];
	}
	tmp.type = EMPTY;
	return (tmp);
}

// t_token	take_space(char *inp)
// {
	// int 	i;
	// int		n;
	// t_token tmp;
	// 
	// i = -1;
	// n = 0;
	// tmp = NULL;
// }

int	ft_lexer(char *inp)
{
	int		i;
	t_token	tmp;

	i = -1;
	while (inp[++i])
	{
		if (inp[i] == 34 || inp[i] == 39)
			tmp = take_quote(inp, inp[i], i);
		printf("%d\n%s\n", tmp.type, tmp.name);
		// if (inp[i] == ' ')
			// take_space(inp);
		// else if (inp[i] == '$')
		// else if (inp[i] == '<')
		// else if (inp[i] == '>')
	}
	return(0);
}
