/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:57:03 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/14 15:23:15 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* void	ft_child(t_shell *shell, t_tokens *tokens, int *fd)
{
	t_tokens	*tmp;

	tmp = tokens;
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (tmp->type == 0)
		ft_builtins(shell);
	else
		ft_execve(shell);
	exit (0);
}

void	ft_parent(t_shell *shell, t_tokens *tokens, int *fd, int pid)
{
	t_tokens	*tmp;

	tmp = tokens;
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if (tmp->type != 7)
		waitpid(pid, NULL, 0);
	tmp = tmp->next;
	if (tmp->next != NULL)
		ft_more_cmds(shell, tmp);
	else
	{
		if (tmp->type == 0)
			ft_builtins(shell);
		else
			ft_child(shell, tmp, fd);
	}
}

void	ft_more_cmds(t_shell *shell, t_tokens *tokens)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_child(shell, tokens, fd);
	else
		ft_parent(shell, tokens, fd, pid);
}
 */