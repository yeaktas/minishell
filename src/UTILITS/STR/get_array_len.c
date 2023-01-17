/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_array_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:21:52 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:21:52 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_array_len(char **array)
{
	int	count;

	count = 0;
	while (array && *(array++))
		count++;
	return (count);
}
