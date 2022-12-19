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

	while(1)
	{
		str = input(env[0]);
		if(str[0] == '[')
			break;
		lexer(str);
	}
}

