/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:28:39 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/07 01:28:39 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executer(void)
{
	if (!g_core.cmd_table)
		return ;
	else if (!g_core.cmd_table->next)
		run_single_command(g_core.cmd_table, NULL);
	else
		run_multiple_command(g_core.cmd_table);
}
