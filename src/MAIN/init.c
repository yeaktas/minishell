/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:18:57 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:18:57 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_core(char **env)
{
	fill_envs(env);
	set_metachars();
	set_title();
	g_core.exec_output = 0;
	g_core.old_exec_output = 0;
	g_core.main_pid = getpid();
}
