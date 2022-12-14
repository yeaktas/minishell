/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tacikgoz <tacikgoz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:35:20 by ekaymaz           #+#    #+#             */
/*   Updated: 2022/12/14 15:42:46 by tacikgoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//girilen dizi starttan len e kadar yazdirilir.

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - start;
	if (len < i)
		i = len;
	if (start > ft_strlen(s) - 1)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, i + 1);
	return (str);
}
/* 
int main(void)
{
	char a[] = "giresun";
	printf("%s", ft_substr(a, 3, 3));
}
*/