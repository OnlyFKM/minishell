/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:39:05 by yfang             #+#    #+#             */
/*   Updated: 2024/03/07 17:22:03 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_view(t_shell *shell)
{
	t_tokens	*tmp;
	t_env		*aux;

	tmp = shell->tokens;
	aux = shell->env;
	while (tmp)
	{
		ft_printf("%s%s, %i, %i%s", YELLOW, tmp->str, tmp->type, tmp->space, END);
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
	while (aux)
	{
		//ft_printf("%s, %s\n", aux->name, aux->content);
		if (aux->next)
			aux = aux->next;
		else
			break ;
	}
}

void	ft_loop(t_shell *shell)
{
	while (1)
	{
		shell->line = readline("marinashell-0.1$ ");
/* 		if (ft_strncmp(shell->line, "\0", 1))
			add_history(shell->line); */
		ft_tokenizer(shell);
		ft_expand(shell);
		if (ft_strncmp(shell->tokens->str, "exit", 4) == 0)
			exit(1);
		if (ft_strncmp(shell->tokens->str, "env", 3) == 0)
			ft_print_env(shell->env);
		ft_view(shell);
		ft_free_loop(shell);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_shell	*shell;

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
