/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:16:40 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:16:40 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*create_pipe(void)
{
	int		index;
	int		*fd;

	fd = (int *)malloc(sizeof(int) * 6);
	index = -1;
	while (++index < 6)
		fd[index] = 0;
	return (fd);
}

void	clear_pipe(int *fd)
{
	int	index;

	if (fd)
	{
		index = -1;
		while (++index < 6)
		{
			if (fd[index])
				close(fd[index]);
		}
		free(fd);
	}
}

void	switch_pipe(int **fd)
{
	(*fd)[0] = (*fd)[0] ^ (*fd)[2];
	(*fd)[2] = (*fd)[0] ^ (*fd)[2];
	(*fd)[0] = (*fd)[0] ^ (*fd)[2];
	(*fd)[1] = (*fd)[1] ^ (*fd)[3];
	(*fd)[3] = (*fd)[1] ^ (*fd)[3];
	(*fd)[1] = (*fd)[1] ^ (*fd)[3];
	(*fd)[5] = (*fd)[5] ^ (*fd)[3];
	(*fd)[3] = (*fd)[5] ^ (*fd)[3];
	(*fd)[5] = (*fd)[5] ^ (*fd)[3];
	(*fd)[4] = (*fd)[2] ^ (*fd)[4];
	(*fd)[2] = (*fd)[2] ^ (*fd)[4];
	(*fd)[4] = (*fd)[2] ^ (*fd)[4];
}
