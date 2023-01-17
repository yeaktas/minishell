/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaktas <yaktas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:18:17 by yaktas            #+#    #+#             */
/*   Updated: 2023/01/17 15:18:18 by yaktas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Lexer 4 asamali prjenin ilk asamasidir. Burada amac
	girilen karisik komutlari sozcuk yapilarina ayirmaktir.
	orn komut: <a.txt cat| ls| wc -l | echo "ahmet $HOME''"selam'$PATH'
	lexer calistiktan sonra bagil liste deki
	contentlerin ciktisi soyle olmalidir:
	<, a.txt, cat, |, ls, |, wc, -l, |, echo, "ahmet $HOME''"selam'$PATH'
*/
void	lexer(void)
{
	g_core.lex_table = NULL;
	create_lexlist(g_core.cmd, &(g_core.lex_table));
	classify(g_core.lex_table);
	syntax_check();
}
