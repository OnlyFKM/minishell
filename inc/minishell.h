/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:40:30 by yfang             #+#    #+#             */
/*   Updated: 2024/03/05 16:55:59 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---------------------------------   LIBS   ---------------------------------*/
# include "Libft/include/libft.h"
// Global
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>

/*--------------------------------   MACROS   --------------------------------*/
// Types
# define BUILTING 0
# define CMD 1
# define ARG 2
# define DOUBLE 3
# define SIMPLE 4
# define OUT 5
# define IN 6
# define APPEND 7
# define INSOURCE 8
# define PIPE 9

// Std
# define STDIN 0
# define STDOUT 1

// Colors
# define RESET "\033[0;m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"

/*--------------------------------   STRUCTS   -------------------------------*/
typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

typedef struct s_tokens
{
	char			*str;
	int				type;
	int				space;
	struct s_tokens	*next;
}	t_tokens;

typedef struct s_shell
{
	t_env			*env;
	t_tokens		*tokens;
	char			**envp;
	char			*line;
}	t_shell;

/*-------------------------------   FUNCTIONS   ------------------------------*/
//	Init
//		init
int			ft_init(t_shell	*shell, char **envp);
//		tokens
void		ft_tokenizer(t_shell *shell);
void		ft_init_token(t_shell *shell, int type, char *str);
//		tokenizer
void		ft_token(t_shell *shell, int *i);
void		ft_token_in_quotes(t_shell *shell, int *i);
//		tokenizer2
void		ft_token_redirections(t_shell *shell, int *i);
//	Utils
//		messages
void		ft_welcome(void);
//		is
int			ft_isspace(int c);
int			ft_isspecial(char c);
//		libftplus
char		*ft_strndup(const char *s, size_t n);
//		t_tokens
t_tokens	*ft_newtoken(int type, char *str);
void		ft_addbacktoken(t_tokens **token, t_tokens *new);
t_tokens	*ft_lasttoken(t_tokens *token);
//	Free
void		ft_free_loop(t_shell *shell);

#endif