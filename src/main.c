/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:01:20 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/14 17:01:32 by frcastil         ###   ########.fr       */
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

void	ft_builtins(t_shell *shell)
{
	if (ft_strncmp(shell->tokens->str, "pwd\0", 4) == EXIT_SUCCESS)
		ft_pwd(shell);
	else if (ft_strncmp(shell->tokens->str, "echo\0", 5) == EXIT_SUCCESS)
		ft_echo(shell->tokens);
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
			ft_tokenizer(shell);
			/* 		ft_expand(shell); */
			ft_count_cmd(shell);
			if (shell->count_cmd == 1)
			{
				if (shell->tokens->type == 0)
					ft_builtins(shell);
				/* else
					ft_execve_one(shell); */
			}
			/* if (shell->count_cmd >= 2)
				ft_more_cmds(shell, shell->tokens); */
		}
		ft_view(shell); // borrar
		ft_free_loop(shell);
		// exit(0);
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
