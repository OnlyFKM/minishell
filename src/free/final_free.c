/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:22:28 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/29 15:03:34 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_free_execve(char **str, char **envp, char *cmd, char *path)
{
	if (str)
		ft_free_double(str);
	if (envp)
		ft_free_double(envp);
	if (cmd)
		free(cmd);
	if (path)
		free(path);
}

/* void	ft_free_execve(char **str, char **envp, char *cmd, char *path)
{
	if (str)
		ft_free_double(str);
	if (envp)
		ft_free_double(envp);
	if (cmd)
		free(cmd);
	if (path)
		free(path);
} */

void	ft_free_loop(t_shell *shell)
{
	dup2(shell->in, STDIN_FILENO);
	dup2(shell->out, STDOUT_FILENO);
	ft_free_tokens(&shell->tokens);
	shell->tokens = NULL;
	shell->count_cmd = 0;
	free(shell->line);
	shell->line = NULL;
}
