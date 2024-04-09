/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:22:28 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/09 12:16:25 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_free_execve(char **str, char **envp, char *cmd, char *path)
{
	if (str != NULL)
		ft_free_double(str);
	if (envp != NULL)
		ft_free_double(envp);
	if (cmd != NULL)
		free(cmd);
	if (path != NULL)
	{
		free(path);
		path = NULL;
	}
}

void	ft_free_loop(t_shell *shell)
{
	//g_signal = 0;
	dup2(shell->in, STDIN_FILENO);
	dup2(shell->out, STDOUT_FILENO);
	ft_free_tokens(&shell->tokens);
	shell->tokens = NULL;
	shell->count_cmd = 0;
	free(shell->line);
	shell->line = NULL;
	shell->path = NULL;
	shell->flag = 0;
}
