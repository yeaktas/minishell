/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:19:02 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:19:03 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	init_core(env);
	signal(SIGINT, &sig_handler);
	while (1)
	{
		update_loop();
		g_core.cmd = readline(g_core.title.full_title);
		exit_signal_check();
		lexer();
		expander();
		parser();
		executer();
		update_history(g_core.cmd);
		free_for_loop();
	}
	free_core();
}
