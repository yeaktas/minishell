/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:20:38 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:20:38 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*valid_env(char *env)
{
	int	flag;

	flag = 0;
	if ((*env >= 'a' && *env <= 'z') || (*env >= 'A' && *env <= 'Z'))
		flag = 1;
	while (*env != ' ' && *env && *env != '=')
	{
		if ((*env > '0' && *env < '9' && !flag)
			|| compare_metachars(env))
			return (NULL);
		env++;
	}
	return (env);
}

char	*env_name_control(char *env)
{
	char	*env_temp;

	if (!env || *env == ' ' || *env == '=')
		return (NULL);
	env_temp = env;
	env_temp = valid_env(env_temp);
	if (!env_temp || (*env_temp != '=' && *env_temp))
		return (NULL);
	if (*env_temp == '=')
		return (++env_temp);
	else
		return (env_temp);
}

int	env_arg_control(char *env)
{
	if (env_name_control(env))
		return (1);
	print_error("-bash: export: `", env, "': not a valid identifier\n");
	g_core.exec_output = 1;
	return (0);
}
