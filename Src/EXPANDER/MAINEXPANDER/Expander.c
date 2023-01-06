/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:29:50 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/07 01:29:50 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander(void)
{
	if (g_core.exec_output == 2)
		return ;
	expand_values_from_lexlist();
	clear_void_contents();
}
