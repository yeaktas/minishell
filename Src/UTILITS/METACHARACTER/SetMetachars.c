/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetMetachars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:34:17 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/07 01:34:17 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	global degiskende ki metachars degiskenine 2 boyutlu bir dizi olusturur
	ve icerisine teker teker belirlenen metakarakterleri atar.
	metakarakterler sirasiyla ">>", "<<", "<", ">", "|"'dir
*/
void	set_metachars(void)
{
	char	**meta_list;

	meta_list = (char **)malloc(sizeof(char *) * (METACHAR_NUM + 1));
	g_core.metachars = meta_list;
	*(meta_list++) = ft_strdup(DOUBLE_GREAT);
	*(meta_list++) = ft_strdup(DOUBLE_LESS);
	*(meta_list++) = ft_strdup(SINGLE_LESS);
	*(meta_list++) = ft_strdup(SINGLE_GREAT);
	*(meta_list++) = ft_strdup(PIPE);
	*(meta_list++) = NULL;
}
