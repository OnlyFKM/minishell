/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:12:52 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/16 10:38:59 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---------------------------------   LIBS   ---------------------------------*/
# include "libft/include/libft.h"
// Global
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

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
# define HERE_DOC 8
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
# define END "\033[0m"

// Int max min
# define MAX 2147483647
# define MIN -2147483648

int					g_signal;

/*--------------------------------   STRUCTS   -------------------------------*/
typedef struct s_env
{
	char			*name;
	char			*content;
	int				flag;
	struct s_env	*next;
}					t_env;

typedef struct s_tokens
{
	char			*str;
	char			*path;
	int				type;
	int				space;
	int				infile;
	int				outfile;
	struct s_tokens	*next;
}					t_tokens;

typedef struct s_shell
{
	t_env			*env;
	t_tokens		*tokens;
	t_tokens		*export;
	char			**envp;
	char			*line;
	char			*tmp_cd;
	char			*pwd;
	char			*path;
	int				count_cmd;
	int				space;
	int				in;
	int				out;
	int				status;
	int				cmdflag;
	int				error;
	int				flag;
}					t_shell;

/*-------------------------------   FUNCTIONS   ------------------------------*/

//		main.c
int					main(int argc, char *argv[], char **envp);
void				ft_loop(t_shell *shell);
void				ft_inside_loop(t_shell *shell);
void				ft_builtins(t_shell *shell, char *str);

int					ft_isredi(int c);
t_env				*ft_newenv(char *name, char *content);
void				ft_init_env(t_shell *shell, char *name, char *content);

//	Utils
//		checks.c
void				ft_check_builtings(t_shell *shell);
void				ft_checkascii(t_shell *shell);
void				ft_checkpipe(t_shell *shell);

//		is.c
int					ft_isspace(int c);
int					ft_isspecial(char c);
int					ft_spandchar(char c);
int					ft_ifredi(char c);
int					ft_isredi(int c);

//		libftplus.c
char				*ft_strndup(const char *s, size_t n);
char				*ft_strjoin_space(char *s1, char *s2);
void				ft_ifspace(t_shell *shell, int i);

//		list.c
int					ft_nodesize(t_env *env);
void				ft_nodeadd_back(t_env **env, t_env *new);
t_env				*ft_nodelast(t_env *env);
int					ft_tokensize(t_tokens *lst);

//		t_tokens.c
t_tokens			*ft_newtoken(int type, char *str, int space);
void				ft_addbacktoken(t_tokens **token, t_tokens *new);
t_tokens			*ft_lasttoken(t_tokens *token);
t_tokens			*ft_newcopytoken(t_tokens *token);
void				ft_copytoken(t_tokens *token, t_shell *shell);

//		utils.c
int					ft_whitespace(char *str);
int					ft_special_char(char sp);
int					ft_first_equal(char *str);
void				ft_count_cmd(t_shell *shell);

//		signals.c
void				ft_sigint(int signum);

//		welcome.c
void				ft_welcome(void);
void				ft_error(t_shell *shell);

//	Tokendepure
//		agroup.c
void				ft_agroup(t_shell *shell);
void				ft_agroup_pipes(t_shell *shell);
int					ft_tokentype(int type);

//		createredi.c
int					ft_heredoc(t_tokens *cmd, t_tokens *redi, t_shell *shell);
void				ft_out(t_tokens *cmd, t_tokens *redi, t_shell *shell);
void				ft_in(t_tokens *cmd, t_tokens *redi, t_shell *shell);

//		expand_utils.c
char				*ft_createdst(t_tokens *token, int i, int j, int status);
void				ft_disexpand(t_tokens *token, int start, int len);
void				ft_final_expand(t_env *env, t_tokens *token, int start,
						int len);

//		expand.c
void				ft_expand(t_shell *shell);

//		redi.c
void				ft_quitredi(t_shell *shell);
int					ft_heredoc(t_tokens *cmd, t_tokens *redi, t_shell *shell);
char				*ft_takename(t_tokens *redi);

//		removeredi.c
void				ft_removeredi(t_shell *shell);
void				ft_miniremoveredi(t_tokens *tmp, t_tokens *aux);
void				ft_miniagroup(t_shell *shell);
void				ft_miniagroup_one(t_tokens *aux, t_tokens *tmp);
void				ft_miniagroup_two(t_tokens *tmp, t_tokens *aux);

//		save_export.c
void				ft_saveexport(t_shell *shell);
int					ft_onlyexport(t_tokens *token);
//  Pipex
//		utils_pipex.c
char				*ft_find_path(t_shell *shell, char *cmd);
char				**ft_update_envp(t_shell *shell);
void				ft_do_execve(t_shell *shell, t_tokens *tokens, int flag);
void				ft_execve_one(t_shell *shell, t_tokens *tokens);
int					ft_check_path(t_shell *shell, t_tokens *tokens);

//		planner.c
void		ft_more_cmds(t_shell *shell, t_tokens *tokens);
void		ft_parent(t_shell *shell, t_tokens *tokens, int *fd, int pid);
void		ft_child(t_shell *shell, t_tokens *tokens, int *fd);
void		ft_execve(t_shell *shell, t_tokens *tokens);

//		heredoc.c
void				ft_pipex(t_shell *shell, t_tokens *tokens);
int					ft_check_fullpath(t_shell *shell);
int					ft_path(t_shell *shell);
void				ft_execve_msg(t_shell *shell, char **str);

//	Init
//		init.c
int					ft_init(t_shell *shell, char **envp);
void				ft_first_pwd(t_shell *shell);
//		minitokenizer.c
t_tokens			*ft_minitokenizer(t_tokens *token, char *str);
//		tokenizer.c
void				ft_token(t_shell *shell, int *i);
void				ft_token_in_quotes(t_shell *shell, int *i);
int					ft_quotes(t_shell *shell, int *i);
void				ft_ifspace(t_shell *shell, int i);

//		tokenizer2.c
void				ft_token_redirections(t_shell *shell, int *i);
int					ft_redirectiontype(char *start);
int					ft_redirections(t_shell *shell, int *i);
int					ft_checkredi(t_tokens *token);

//		tokens.c
void				ft_tokenizer(t_shell *shell);
void				ft_init_token(t_shell *shell, int type, char *str);

//	Free
//		final_free.c
void		ft_free_execve(char **str, char **envp, char *cmd, char *path);
void		ft_free_loop(t_shell *shell);

//		free.c
void				ft_free_tokens(t_tokens **tokens);
void				ft_free_double(char **str);
void				ft_free_env(t_env *env);
void				ft_free_exit(t_shell *shell);

//	Builtins
//		basics.c
void		ft_pwd(t_shell *shell);
void		ft_exit(t_shell *shell, t_tokens *tokens);
void		ft_check_number(t_shell *shell, t_tokens *tokens);
void		ft_status_exit(t_shell *shell, t_tokens *tokens, long status);

//		cd_utils.c
void				ft_search_dir(t_shell *shell, char *find);
void				ft_oldpwd(t_shell *shell);
void				ft_change_pwd(t_shell *shell);

//		cd.c
void				ft_cd(t_shell *shell, t_tokens *tokens);
void				ft_cd_next(t_shell *shell, t_tokens *tokens);
void				ft_first_cd(t_shell *shell);
int					ft_check_oldpwd(t_shell *shell);

//		echo.c
void				ft_echo(t_shell *shell, t_tokens *list);
int					ft_check_n(t_tokens *check);
void				ft_print_echo(t_tokens *list, int flag);

//		env.c
void				ft_env(t_shell *shell, char **envp);
void				ft_create_node_env(t_env *env);
void				ft_print_env(t_env *env);
void				ft_dupenvp(t_shell *shell, char **envp);

//		export_utils.c
void				ft_print_export(char **export);
void				ft_order_export(char **str);
void				ft_check_start(t_shell *shell, char *first, char *second);
void				ft_add_export(t_shell *shell, char *first, char *second);
int					ft_ifoutorin(t_tokens *aux);

//		export.c
void				ft_export(t_shell *shell, t_tokens *tokens);
void				ft_create_export(t_env *env);
int					ft_check_export(t_env *env, char *first, char *second);
void				ft_create_pointers(t_shell *shell, char *str);
void				ft_create_pointers_2(t_shell *shell, char *str, int j);

//		unset.c
void				ft_unset(t_shell *shell, char *str);
void				ft_unset_loop(t_shell *shell, t_tokens *tokens);

#endif