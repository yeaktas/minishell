/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:17:12 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:17:12 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_envs(char **dst, char *ptr)
{
	t_env	*copy_envs;

	copy_envs = g_core.env_table;
	while (copy_envs)
	{
		if (str_compare(ptr, copy_envs->env_name))
		{
			own_strjoin(dst, copy_envs->content);
			break ;
		}
		copy_envs = copy_envs->next;
	}
}

void	expand_order(char **dst, char **src)
{
	if (**src == *DOLLAR)
		expand_dollar(dst, src);
	else
		expand_envs(dst, "HOME");
}
