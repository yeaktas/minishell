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
	printf("%d\n", big_a$$->token->type);
}

char	*ft_linecheck(char *inp, char c)
{
	int i;
	int n = 0;
	i = -1;
	while(inp[++i])
	{
		if (inp[i] == c)
		{
			n = i;
			while(inp[++n])
			{
				if(inp[n] == c)
					printf("basarili\n");
				else if (inp[n] == '\n')
					printf("basarisiz\n");
				fflush(stdout);
			}
		}
	}
	return (inp);
}

int	ft_lexer(char *inp)
{
	int		i;
	int		wcount;
	char	**word;

	i = -1;
	wcount = word_count(inp);
	ft_linecheck(inp, 34);
	ft_linecheck(inp, 39);
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
