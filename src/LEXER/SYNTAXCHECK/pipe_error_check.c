/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_error_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:18:40 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:18:40 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_error_check(t_lexlist *lex_list)
{
	if (lex_list->next && lex_list->next->type == SIGN_PIPE)
		return (print_lex_error(lex_list));
	else if (!lex_list->next)
		return (run_miss_arg(lex_list));
	return (1);
}

int	run_miss_arg(t_lexlist *lex_list)
{
	char	*ptr;

	ptr = get_missing_arg();
	if (!ptr)
		return (1);
	create_lexlist(ptr, &lex_list);
	classify(lex_list);
	str_addchar(&g_core.cmd, ' ');
	own_strjoin(&g_core.cmd, ptr);
	free(ptr);
	if (str_compare(lex_list->next->content, PIPE))
		return (-1);
	return (1);
}
