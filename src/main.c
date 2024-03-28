/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:01:20 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/28 18:10:31 by yfang            ###   ########.fr       */
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
		ft_printf("%s%s, %i, %i%s\n", YELLOW, tmp->str, tmp->type, tmp->space,
			END);
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
	ft_view2(aux); //borrar
	if (ft_strncmp(shell->tokens->str, "pwd\0", 4) == EXIT_SUCCESS)
		ft_pwd(shell);
	else if (ft_strncmp(aux->str, "echo\0", 5) == EXIT_SUCCESS)
		ft_echo(aux);
	else if (ft_strncmp(shell->tokens->str, "game\0", 5) == EXIT_SUCCESS)
		printf("YOU HAVE LOST THE GAME\n");
	else if (ft_strncmp(shell->tokens->str, "marina\0", 7) == EXIT_SUCCESS)
		printf("Marina, DO NOT DELETE my home pls\n");
	else if (ft_strncmp(shell->tokens->str, "env\0", 4) == EXIT_SUCCESS)
		ft_print_env(shell->env);
	else if (ft_strncmp(shell->tokens->str, "exit\0", 5) == EXIT_SUCCESS)
		ft_exit(shell);
	else if (ft_strncmp(shell->tokens->str, "unset\0", 6) == EXIT_SUCCESS)
		ft_unset_loop(shell, shell->tokens->next);
	else if (ft_strncmp(shell->tokens->str, "export\0", 7) == EXIT_SUCCESS)
		ft_export(shell);
	else if (ft_strncmp(shell->tokens->str, "cd\0", 3) == EXIT_SUCCESS)
		ft_cd(shell);
	ft_free_tokens(&aux);
}

void	ft_inside_loop(t_shell *shell)
{
	ft_tokenizer(shell);
	ft_view(shell); // borrar
	ft_expand(shell);
	if (shell->tokens->next)
		ft_agroup(shell);
	ft_agroup_pipes(shell);
	ft_count_cmd(shell);
	if (shell->count_cmd == 1)
	{
		if (shell->tokens->type == 0)
			ft_builtins(shell, shell->tokens->str);
/* 		else
			ft_execve_one(shell); */
	}
/* 	if (shell->count_cmd >= 2)
		ft_more_cmds(shell, shell->tokens); */
}

void	ft_loop(t_shell *shell)
{
	while (1)
	{
		shell->line = readline("marinashell$ ");
		if (ft_strncmp(shell->line, "\0", 1))
			add_history(shell->line);
		if (!ft_whitespace(shell->line))
		{
			/* ft_inside_loop(shell); */
			ft_tokenizer(shell);
			ft_expand(shell);
			if (shell->tokens->next)
				ft_agroup(shell);
			ft_agroup_pipes(shell);
			ft_count_cmd(shell);
			ft_view(shell); // borrar
			if (shell->count_cmd == 1)
			{
				if (shell->tokens->type == 0)
					ft_builtins(shell, shell->tokens->str);
				/* else
					ft_execve_one(shell); */
			}
		}
		//ft_view(shell); // borrar
		ft_free_loop(shell);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_shell	*shell;

	atexit(ft_leaks);
	(void)argv;
	if (argc == 1)
	{
		ft_welcome();
		shell = ft_calloc(1, sizeof(t_shell));
		ft_init(shell, envp);
		ft_loop(shell);
	}
	return (EXIT_SUCCESS);
}
