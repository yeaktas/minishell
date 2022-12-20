#include "minishell.h"


t_token *token_content(t_list *l_token)
{
	return ((t_token *)l_token->content);
}

t_list	*token_create(char *string, int type) //disaridan token tipini(text, |,<,>) ve makrosunu aliyor.
{
	t_token *t_tok;
	t_list *token;

	t_tok = malloc(sizeof(t_token));
	if (t_tok == NULL)
		return (NULL);
	t_tok->flags = type;
	t_tok->str = string;
	token = ft_lstnew(t_tok);
	if (token == NULL)
		return (NULL);
	token->next = NULL;
	return (token);
}

void	c_token_destroy(void *c_token)
{
	free(((t_token *)c_token)->str);
	((t_token *)c_token)->str = NULL;
	free(c_token);
}

/*
 * Function that adds the element 'new' at the end of the linked list 'lst'.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
		*lst = new;
	else
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}
/*
 * Function that uses malloc to create a new list element, where the 'content'
 * pointer of the element is initialized with the value of the parameter
 * 'content' and the 'next' pointer is set to NULL.
 * 
 * 
	Yeni bir liste öğesi oluşturmak için malloc kullanan işlev; burada 'content'
 	elemanın işaretçisi, parametrenin değeri ile başlatılır
	'content' ve 'next' işaretçi NULL olarak ayarlanır.
 * 
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}