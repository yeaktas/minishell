#include "minishell.h"

static int text_len(char *str);

int	lexer_token_text(char *str, int *i, t_list **l_token)
{
	t_list *token;    //t_list tipinde bir token olusturuyoruz.
	char *token_str;
	int len;

	len = text_len(&str[*i]); //textin uzunlugunu aliyor.
	if (len > 0)
	{
		token_str = ft_substr(str, *i, len); //str *i den len'e kadar azdirilip token_strnin icine ekleniyor. yani böylelikle textimizi token_str'ye aktardik.
		if(token_str == NULL)
			return(print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		token = token_create(token_str, TOK_TEXT); //yeni bir token olusuturmak icin token_str'yi TOK_TEXT makrosu ile token_create fonksiyonuna gonderiyoruz.
		if(token == NULL)
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM))); // token olusturulamadiysa hata mesaji bas.
		ft_lstadd_back(l_token, token); //yeni tokenimizi listenin sonuna ekliyor.
		*i += len;
		if(!ft_strchr(WHITESPACE, str[*i]) && other_len(&str[*i]) == 0)
			token_content(token)->flags |= TOK_CONNECTED;
	}
	return(0);
}

//text lenin textin uzunlugunu return etmesini bekliyoruz.
//strnin icinde dolasarak < > >> << | \t\n karakterlerini gorene kadar textin uzunlugunu hesapliyor. 

static int text_len(char *str) // baska bir dosyadan erisilmeyecegi icin fonksiyonu static olarak tanimladik.
{
	int i;

	i = 0;
	while (str[i]) //str null olana kadar calisacak.
	{
		if(ft_strchr(WHITESPACE, str[i])) //" \t\n" karakterleri strnin icinde var mi diye bakiyor.
			break;
		else if (other_len(&str[i]) > 0) // < > | karakterleri strnin icinde var mi diye bakiyor.
			break;
		else if(ft_strchr(QUOTE, str[i])) // "\'\"" karakterleri strnin icinde var mi diye bakiyor.
			break;
		i++;
	}
	return (i);
}