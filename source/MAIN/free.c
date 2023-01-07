/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:31:23 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/07 01:31:23 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_core(void)
{
	free_metachars();
	free_envtable();
	free_title();
	rl_clear_history();
}

void	free_for_loop(void)
{
	if (g_core.cmd)
	{
		free(g_core.cmd);
		g_core.cmd = NULL;
	}
	if (g_core.lex_table)
		free_lexer();
	if (g_core.cmd_table)
		free_parser();
	close_heradoc_file();
}
