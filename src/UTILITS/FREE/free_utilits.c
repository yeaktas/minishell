/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utilits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:21:05 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:21:05 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_metachars(void)
{
	char	**temp_metachars;

	temp_metachars = g_core.metachars;
	if (!temp_metachars)
		return ;
	while (temp_metachars && *temp_metachars)
		free(*(temp_metachars++));
	free(g_core.metachars);
}

void	free_envtable(void)
{
	t_env	*env;
	t_env	*temp_env;

	env = g_core.env_table;
	while (env)
	{
		temp_env = env;
		env = env->next;
		free(temp_env->env_name);
		free(temp_env->content);
		free(temp_env);
	}
}

void	free_title(void)
{
	free(g_core.title.full_title);
	free(g_core.title.head);
}
