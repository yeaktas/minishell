/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:34:45 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/07 01:34:45 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Karakter dizisinin boyutunu alir.
*/

size_t	ft_strlen(char *ptr)
{
	size_t	count;

	count = 0;
	while (ptr && *(ptr++))
		count++;
	return (count);
}
