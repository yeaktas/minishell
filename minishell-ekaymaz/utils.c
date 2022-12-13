#include "minishell.h"

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

t_token	*token_new(void *content)
{
	t_token	*ptr;
	ptr = (t_token *)malloc(sizeof(t_token));
	if (!ptr)
		return (NULL);
	ptr->name = (char *)content;
	ptr->type = EMPTY;
	ptr->next = NULL;
	return (ptr);
}

void	token_add_back(t_token **lst, t_token *new)
{
	t_token	*ptr;

	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}
