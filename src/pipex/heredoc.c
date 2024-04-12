/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:53 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 22:13:52 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_execve_msg(t_shell *shell, char **str)
{
	if (ft_path(shell) == EXIT_SUCCESS)
		ft_printf("marinashell: %s: command not found\n", str[0]);
	else
		ft_printf("marinashell: %s: No such file or directory\n", str[0]);
	shell->status = 127;
}

int	ft_path(t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "PATH") == EXIT_SUCCESS)
			return (EXIT_SUCCESS);
		tmp = tmp->next;
	}
	return (EXIT_FAILURE);
}

int	ft_check_fullpath(t_shell *shell)
{
	if (access(shell->tokens->str, F_OK) == EXIT_SUCCESS)
	{
		shell->path = ft_strdup(shell->tokens->str);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	ft_pipex(t_shell *shell, t_tokens *tokens)
{
	t_tokens	*tmp;

	(void)shell;
	tmp = tokens;
	if (tmp->outfile > 0)
	{
		dup2(tmp->outfile, STDOUT_FILENO);
		close(tmp->outfile);
	}
	if (tmp->infile > 0)
	{
		dup2(tmp->infile, STDIN_FILENO);
		close(tmp->infile);
	}
}
