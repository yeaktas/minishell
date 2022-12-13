#include "minishell.h"

t_big_hole	*big_ass;

void	my_print()
{
	int i;

	i = 0;
	printf("%s ", big_ass->token[i].name);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
}

char	*take_quote(char *inp, char c, int quote)
{
	int	(i) = quote;
	int	(j) = 0;
	char	*tmp;

	while (inp[++i] && ++j)
	{
		if (inp[i] == c)
			break;
	}
	tmp = malloc(sizeof(char) * j);
	tmp[j] = '\0';
	while (quote < j--)
	{
		if(!(tmp[j] == c))
			tmp[j] = inp[quote + j];
	}
	return (tmp);
}

char	*take_space(char *inp, int n)
{
	static int (i) = 0;
	int (j) = 0;
	char *src;

	src = NULL;
	src = malloc(sizeof(char) * (n - i) + 1);
	while(inp[i] == ' ')
		i++;
	while(i < n)
		src[j++] = inp[i++];
	src[j] = '\0';
	return (src);
}

int	ft_lexer(char *inp)
{
	int (i) = -1;

	while (inp[++i] == ' ')
		inp = ft_strtrim(inp, " ");
	i = -1;
	while (inp[++i])
	{
		if (inp[i] == ' ')
			token_new(take_space(inp, i));
		else if (inp[i] == 34 || inp[i] == 39)
			token_new(take_quote(inp, inp[i], i));
	}
	return(0);
}
