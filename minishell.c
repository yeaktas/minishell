#include "minishell.h"

char	*input(char *user)
{
	char	*a;

	user = "tacikgoz % ";
	a = readline(user);
	return (a);
}

int	word_count(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return(count + 1);
}

int	if_command(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != "echo"[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, __attribute__((unused))char **env)
{
	char	*str;

	str = input(env[0]);
	ft_lexer(str);
}
