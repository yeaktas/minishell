#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/* -------------------------------------------------------------------------- */
/* 	CHARACTER																	*/
/* -------------------------------------------------------------------------- */
# define CHAR_PIPE '|'
# define CHAR_AMPERSAND '&'
# define CHAR_QOUTE '\''
# define CHAR_DQUOTE '\"'
# define CHAR_SEMICOLON ';'
# define CHAR_SPACE ' '
# define CHAR_ESCAPESEQUENCE '\\'
# define CHAR_TAB '\t'
# define CHAR_NEWLINE '\n'
# define CHAR_GREATER '>'
# define CHAR_LESSER '<'
# define CHAR_NULL 0

/* -------------------------------------------------------------------------- */
/* 	STRINGS																		*/
/* -------------------------------------------------------------------------- */
# define WHITESPACE " \t\n"
# define QUOTE "\'\""
# define SHELL_NAME "minishell"

/* -------------------------------------------------------------------------- */
/* 	COMMAND FLAG																*/
/* -------------------------------------------------------------------------- */
# define TEXT 1
# define COMMAND 2
# define FLAG 4
# define ARG 8

/* -------------------------------------------------------------------------- */
/* 	RETURN VALUE																*/
/* -------------------------------------------------------------------------- */
# define SUCCESS -1
# define ERROR -2
# define EMPTY -3

/* -------------------------------------------------------------------------- */
/* 	TOKEN FLAG																	*/
/* -------------------------------------------------------------------------- */
# define TOK_TEXT 1
# define TOK_S_QUOTE 2
# define TOK_D_QUOTE 4
# define TOK_REDIR_FILE 8
# define TOK_CONNECTED 16
# define TOK_BIN_OP 32
# define TOK_PIPE 64
# define TOK_BRACKET_OPEN 128
# define TOK_BRACKET_CLOSE 256
# define TOK_REDIR 512
# define TOK_HEREDOC 1024
# define TOK_WILDCARD 2048

/* -------------------------------------------------------------------------- */
/* SYNTAX ERROR																	*/
/* -------------------------------------------------------------------------- */

# define ERR_SYNTAX "syntax error"
# define ERR_SYNTAX_EXIT 2

# define ERR_UNO_BRACKET "unopened brackets"
# define ERR_UNC_BRACKET "unclosed brackets"
# define ERR_EMPTY_BRACKET "empty brackets"
# define ERR_REDIR "invalid redirection"
# define ERR_QUOTE "unclosed quotation mark"
# define ERR_LIST "incomplete command list"
# define ERR_MISS_OP "missing operator"
# define ERR_PIPE "incomplete pipe"

/* -------------------------------------------------------------------------- */
/* 																		*/
/* -------------------------------------------------------------------------- */
# define EPERM 1    /* Operation not permitted */
# define ENOENT 2   /* No such file or directory */
# define ESRCH 3    /* No such process */
# define EINTR 4    /* Interrupted system call */
# define EIO 5      /* Input/output error */
# define ENXIO 6    /* Device not configured */
# define E2BIG 7    /* Argument list too long */
# define ENOEXEC 8  /* Exec format error */
# define EBADF 9    /* Bad file descriptor */
# define ECHILD 10  /* No child processes */
# define EDEADLK 11 /* Resource deadlock avoided */
					/* 11 was EAGAIN */
# define ENOMEM 12  /* Cannot allocate memory */
# define EACCES 13  /* Permission denied */
# define EFAULT 14  /* Bad address */
# if __DARWIN_C_LEVEL >= __DARWIN_C_FULL
#  define ENOTBLK 15 /* Block device required */
# endif
# define EBUSY 16   /* Device / Resource busy */
# define EEXIST 17  /* File exists */
# define EXDEV 18   /* Cross-device link */
# define ENODEV 19  /* Operation not supported by device */
# define ENOTDIR 20 /* Not a directory */
# define EISDIR 21  /* Is a directory */
# define EINVAL 22  /* Invalid argument */
# define ENFILE 23  /* Too many open files in system */
# define EMFILE 24  /* Too many open files */
# define ENOTTY 25  /* Inappropriate ioctl for device */
# define ETXTBSY 26 /* Text file busy */
# define EFBIG 27   /* File too large */
# define ENOSPC 28  /* No space left on device */
# define ESPIPE 29  /* Illegal seek */
# define EROFS 30   /* Read-only file system */
# define EMLINK 31  /* Too many links */
# define EPIPE 32   /* Broken pipe */

/* -------------------------------------------------------------------------- */
/* 	STRUCTS																		*/
/* -------------------------------------------------------------------------- */
typedef struct s_token
{
	char	*str;
	int		flags;
}			t_token;

typedef struct s_big_hole
{
	char	**word;
	char	**env;
	t_token	*token;
}			t_big_hole;

//minishell.c

//ultra_mega_split.c

//lexer_utils.c
int			quote_len(char *str);
void		c_token_destroy(void *c_token);
t_list		*token_create(char *string, int type);
t_token		*list_to_token(t_list *l_token);
int			other_len(char *chr);

//lexer.c
t_list	*lexer(char *input);
char		*take_quote(char *inp, char c, int quote);
char		*take_space(char *inp, int n);
int			lexer_token_text(char *str, int *i, t_list **l_token);

//lexer2.c
int lexer_token_pipe(char *str, int *i, t_list **l_token);
int			lexer_token_bracket(char *str, int *i, t_list **l_token);
// static int	syntax_pipe(t_list *l_token);

//lexer3.c
int	lexer_token_redir(char *str, int *i, t_list **l_token);
t_list		*token_create(char *string, int type);
int	lexer_token_bracket(char *str, int *i, t_list **l_token);
t_token		*token_content(t_list *token);
int			other_len(char *chr);
int			lexer_token_quote(char *str, int *i, t_list **l_token);
// static int	syntax_brackets(t_list *l_token);

//utils.c
int			word_count(char *str);
t_token		*token_new(void *content);
void		token_add_back(t_token **lst, t_token *new);

//print_error.c
int			print_error(char *s1, char *s2, char *s3, char *message);
char		*strerror(int __errnum) __DARWIN_ALIAS(strerror);
int			print_error_errno(char *s1, char *s2, char *s3);

#endif