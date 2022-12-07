#include "minishell.h"

char	*input(char *user)
{
	char	*a;

	user = "tacikgoz % ";
	a = readline(user);
	return (a);
}

void	abo(t_big_hole *a)
{
	a->token->type = 2;
}

int	main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, __attribute__((unused))char **env)
{
	char	*str;

	str = input(env[0]);
	ft_lexer(str);
}
