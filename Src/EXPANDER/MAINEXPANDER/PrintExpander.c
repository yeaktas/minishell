/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintExpander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:29:55 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/07 01:29:55 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_expander(void)
{
	t_lexlist	*lexer_temp;

	lexer_temp = g_core.lex_table;
	printf ("~EXPANDER TABLE~\n");
	while (lexer_temp)
	{
		printf("{type: %d, content: %s}\n", lexer_temp->type,
			lexer_temp->content);
		lexer_temp = lexer_temp->next;
	}
	printf("\n\n");
}
