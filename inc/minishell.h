/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:12:52 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/13 19:13:16 by yfang            ###   ########.fr       */
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
	char			*tmp_cd;
	char			*pwd;
	int				count_cmd;
}					t_shell;

// main.c
void				ft_builtins(t_shell *shell);
void				ft_loop(t_shell *shell);
int					main(int argc, char *argv[], char **envp);

////////////////////	utils

//	welcome.c
void				ft_welcome(void);

//	utils.c
int					ft_special_char(char sp);
int					ft_whitespace(char *str);
int					ft_first_equal(char *str);
void				ft_count_cmd(t_shell *shell);
void				ft_check_builtings(t_shell *shell);

// list.c
int					ft_nodesize(t_env *env);
void				ft_nodeadd_back(t_env *env, t_env *new);
t_env				*ft_nodelast(t_env *env);

////////////////////	init

//	init.c
int					ft_init(t_shell *shell, char **envp);

////////////////////	builtins

//	basics.c
void				ft_pwd(t_shell *shell);
void				ft_exit(t_shell *shell);
void				ft_check_number(t_shell *shell);
void				ft_status_exit(t_shell *shell, int status);

//	cd.c
void				ft_cd(t_shell *shell);
void				ft_cd_next(t_shell *shell);
void				ft_tmp(t_shell *shell, char *cwd);
void				ft_first_cd(t_shell *shell);
int					ft_check_oldpwd(t_shell *shell);

// cd_utils.c
void				ft_search_dir(t_shell *shell, char *find);
void				ft_oldpwd(t_shell *shell);
void				ft_oldpwd_2(t_shell *shell, char *pwd);
void				ft_change_pwd(t_shell *shell);
void				ft_add_pwd(t_shell *shell);

//	unset.c
void				ft_unset_loop(t_shell *shell, t_tokens *prueba);
void				ft_unset(t_shell *shell, char *str);

//	echo.c
void				ft_echo(t_tokens *list);
int					ft_check_n(t_tokens *check);
void				ft_exec_echo(t_tokens *check, int flag);
void				ft_print_echo(t_tokens *list, int flag);

//	env.c
void				ft_env(t_env *env, char **envp);
void				ft_search_oldpwd(t_env *env);
void				ft_create_node_env(t_env *env);
void				ft_print_env(t_env *env);
void				ft_dupenvp(t_shell *shell, char **envp);

// export.c
void				ft_export(t_shell *shell);
void				ft_create_export(t_env *env);
int					ft_check_export(t_env *env, char *first, char *second);
void				ft_create_pointers(t_shell *shell, char *str);
void				ft_create_pointers_2(t_shell *shell, char *str, int j);

// utils_export.c
void				ft_add_export(t_shell *shell, char *first, char *second);
void				ft_print_export(char **export);
void				ft_order_export(char **str);
void				ft_check_start(t_shell *shell, char *first, char *second);

////////////////////	free

//	free.c
void				ft_free_loop(t_shell *shell);

// final_free.c
void				ft_free_exit(t_shell *shell);
void				ft_prueba(t_tokens *prueba);
void				ft_free_env(t_env *env);
void				ft_free_double(char **str);

////////////////////	pipex

//	execution.c
void				ft_execve(t_shell *shell);
char				*ft_find_path(t_shell *shell, char *cmd);
char				**ft_update_envp(t_shell *shell);
char				**ft_pointer_str(t_shell *shell);
void				ft_execve_one(t_shell *shell);

//	planner.c
void				ft_more_cmds(t_shell *shell, t_tokens *tokens);
void				ft_parent(t_shell *shell, t_tokens *tokens, int *fd, int pid);
void				ft_child(t_shell *shell, t_tokens *tokens, int *fd);

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
//		list
int			ft_nodesize(t_env *env);
void		ft_nodeadd_back(t_env *env, t_env *new);
t_env		*ft_nodelast(t_env *env);
//	Tokendepure
//		expand
void		ft_expand(t_shell *shell);
/* void		ft_expand(t_shell *shell); */
//	Builtins
//		env
void		ft_env(t_env *env, char **envp);
void		ft_search_oldpwd(t_env *env);
void		ft_create_node_env(t_env *env);
void		ft_print_env(t_env *env);
void		ft_dupenvp(t_shell *shell, char **envp);
//	Free
void		ft_free_loop(t_shell *shell);

# define END "\033[0m"

#endif