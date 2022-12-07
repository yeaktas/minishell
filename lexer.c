#include "minishell.h"

t_big_hole	*big_a$$;

void	my_print()
{
	int i;

	i = -1;
	while (big_a$$->token[++i].name)
	{
		printf("%s ", big_a$$->token[i].name);
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
	abo(big_a$$);
	printf("%d\n", big_a$$->token->type);
}

int	ft_lexer(char *inp)
{
	int		i;
	int		wcount;
	char	**word;

	i = -1;
	wcount = word_count(inp);
	word = ft_split(inp, ' ');
	big_a$$ = malloc(sizeof(t_big_hole));
	big_a$$->token = malloc(sizeof(t_token) * wcount);
	while (word[++i])
	{
		big_a$$->token[i].name = word[i];
	}
	my_print();
	return(0);
}
