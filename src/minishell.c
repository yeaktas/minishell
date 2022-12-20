#include "minishell.h"

static char	*get_input(char *user);

int	main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
	char	*str;

	str = get_input(env[0]);
	process_input(str);
}

static char	*get_input(char *user)
{
	char	*a;
	char	*tmp;
	(void)user;
	tmp = ft_strjoin(getenv("USER"), " % ");
	a = readline(tmp);
	return (a);

}

void	process_input(char *input)
{
	t_list	*l_token;
	t_list	*l_parser;

	l_token = NULL;
	l_parser = NULL;
	l_token = lexer(input);
	free(input);
	if (l_token != NULL)
		l_parser = parser(l_token);
}