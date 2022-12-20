#include "minishell.h"

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
