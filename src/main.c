/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:01:20 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 16:47:58 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_leaks(void)
{
	system("leaks -q minishell");
}

void	ft_view(t_shell *shell)
{
	t_tokens	*tmp;
	t_env		*aux;

	tmp = shell->tokens;
	aux = shell->env;
	while (tmp)
	{
		ft_printf("%s%s, %i, %i, %i%s\n", YELLOW, tmp->str, tmp->type, tmp->space, shell->cmdflag, END);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	while (aux)
	{
		// ft_printf("%s, %s\n", aux->name, aux->content);
		if (aux->next)
			aux = aux->next;
		else
			break ;
	}
}

void	ft_view2(t_tokens *tokens)
{
	t_tokens	*tmp;

	tmp = tokens;
	while (tmp)
	{
		ft_printf("%s%s, %i, %i%s\n", BLUE, tmp->str, tmp->type, tmp->space,
			END);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
}

void	ft_builtins(t_shell *shell, char *str)
{
	t_tokens	*aux;

	aux = NULL;
	aux = ft_minitokenizer(aux, str);
	//ft_view2(aux); // borrar
	if (ft_strncmp(aux->str, "pwd\0", 4) == EXIT_SUCCESS)
		ft_pwd(shell);
	else if (ft_strncmp(aux->str, "echo\0", 5) == EXIT_SUCCESS)
		ft_echo(shell, aux);
	else if (ft_strncmp(aux->str, "game\0", 5) == EXIT_SUCCESS)
		printf("YOU HAVE LOST THE GAME\n");
	else if (ft_strncmp(aux->str, "marina\0", 7) == EXIT_SUCCESS)
		printf("Marina, DO NOT DELETE my home pls\n");
	else if (ft_strncmp(aux->str, "env\0", 4) == EXIT_SUCCESS)
		ft_print_env(shell->env);
	else if (ft_strncmp(aux->str, "exit\0", 5) == EXIT_SUCCESS)
		ft_exit(shell, aux);
	else if (ft_strncmp(aux->str, "unset\0", 6) == EXIT_SUCCESS)
		ft_unset_loop(shell, aux->next);
	else if (ft_strncmp(aux->str, "export\0", 7) == EXIT_SUCCESS)
		ft_export(shell, shell->export);
	else if (ft_strncmp(aux->str, "cd\0", 3) == EXIT_SUCCESS)
		ft_cd(shell, aux);
	ft_free_tokens(&aux);
}

void	ft_error(t_shell *shell)
{
	if (shell->error == 1)
		ft_printf("marinashell: error for quotes not closed\n");
	if (shell->error == 2)
		ft_printf("marinashell: syntax error near unexpected token '<'\n");
	if (shell->error == 3)
		ft_printf("marinashell: syntax error near unexpected token '>'\n");
	if (shell->error == 4)
	{
		ft_printf("marinashell: syntax error near ");
		ft_printf("unexpected token 'newline'\n");
	}
	if (shell->error == 5)
		ft_printf("marinashell: syntax error near unexpected token '|'\n");
	if (shell->error == 6)
		ft_printf("marinashell: error opening file\n");
	if (shell->error == 7)
		ft_printf("marinashell: syntax error near unexpected token\n");
	if (shell->error == 8)
		ft_printf("marinashell: failure in pipe or fork\n");
	if (shell->error == 10)
		ft_printf("marinashell: syntax error not an ascii char\n");
	shell->status = 1;
}

int	ft_onlyexport(t_tokens *token)
{
	t_tokens	*tmp;

	tmp = token;
	while (tmp && tmp->type != PIPE)
		tmp = tmp->next;
	if (tmp)
		return (0);
	else
		return (1);
}

t_tokens	*ft_newcopytoken(t_tokens *token)
{
	t_tokens	*tmp;

	if (!token)
		return (NULL);
	tmp = ft_calloc(1, sizeof(t_tokens));
	tmp->str = ft_strdup(token->str);
	if (token->path)
		tmp->path = ft_strdup(token->path);
	tmp->type = token->type;
	tmp->space = token->space;
	tmp->infile = token->infile;
	tmp->outfile = token->outfile;
	tmp->next = NULL;
	token = token->next;
	return (tmp);
}

void	ft_copytoken(t_tokens *token, t_shell *shell)
{
	t_tokens	*tmp;

	while (token)
	{
		tmp = ft_newcopytoken(token);
		ft_addbacktoken(&shell->export, tmp);
		token = token->next;
	}
}

void	ft_saveexport(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		//ft_printf("entro aqui\n");
		if (!ft_strncmp(tmp->str, "export\0", 7) && ft_onlyexport(tmp))
			ft_copytoken(tmp, shell);
		tmp = tmp->next;
	}
}

void	ft_checkpipe(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (ft_tokentype(tmp->type))
			if (!tmp->next || ft_strncmp(tmp->str, "|\0", 2))
				shell->error = 5;
		tmp = tmp->next;
	}
}

void	ft_inside_loop(t_shell *shell)
{
	if (shell->tokens->next)
		ft_agroup(shell);
	ft_expand(shell);
	ft_saveexport(shell);
	ft_quitredi(shell);
	ft_checkpipe(shell);
	//ft_view(shell); // borrar
	if (shell->error == 0)
	{
		ft_check_builtings(shell);
		ft_agroup_pipes(shell);
		ft_count_cmd(shell);
		if (shell->count_cmd == 1)
		{
			//ft_view(shell); // borrar
			ft_pipex(shell, shell->tokens);
			if (shell->tokens->type == 0)
				ft_builtins(shell, shell->tokens->str);
			else
				ft_execve_one(shell, shell->tokens);
		}
		else if (shell->count_cmd >= 2)
			ft_more_cmds(shell, shell->tokens);
	}
	else
		ft_error(shell);
}

void	ft_checkascii(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->line[i])
	{
		if (!ft_isascii(shell->line[i]))
			shell->error = 10;
		i++;
	}
}

void	ft_loop(t_shell *shell)
{
	while (1)
	{
		shell->error = 0;
		shell->line = readline("marinashell$ ");
		if (!shell->line)
			ft_exit(shell, NULL);
		ft_checkascii(shell);
		if (ft_strncmp(shell->line, "\0", 1))
			add_history(shell->line);
		if (!ft_whitespace(shell->line))
		{
			ft_tokenizer(shell);
			if (shell->error == 0)
				ft_inside_loop(shell);
			else
				ft_error(shell);
		}
		ft_free_loop(shell);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_shell	*shell;

	(void)argv;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ft_sigint);
	if (argc == 1)
	{
		ft_welcome();
		shell = ft_calloc(1, sizeof(t_shell));
		ft_init(shell, envp);
		ft_loop(shell);
	}
	return (EXIT_SUCCESS);
}
