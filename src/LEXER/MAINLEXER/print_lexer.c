/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:18:22 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:18:22 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_lexer(void)
{
	t_lexlist	*lexer_temp;

	lexer_temp = g_core.lex_table;
	printf ("~LEXER TABLE~\n");
	while (lexer_temp)
	{
		printf("{type: %d, content: %s}\n", lexer_temp->type,
			lexer_temp->content);
		lexer_temp = lexer_temp->next;
	}
	printf("\n\n");
}
