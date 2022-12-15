#include "minishell.h"

char	*input(char *user)
{
	char	*a;
	char	*tmp;
	(void)user;
	tmp = ft_strjoin(getenv("USER"), " % ");
	a = readline(tmp);
	return (a);

}

int	main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
	char	*str;

	str = input(env[0]);
	lexer(str);
}
