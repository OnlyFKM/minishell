/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:57:03 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/29 13:09:22 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_child(t_shell *shell, int *fd)
{
	t_tokens	*tmp;
	/* char		**str;
	char		**envp; */
	tmp = shell->tokens;
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (tmp->type == '0')
		ft_builtins(shell);
	else
		ft_execve(shell);
}

void	ft_parent(t_shell *shell, int *fd)
{
	t_tokens	*tmp;
/* 	char		**str;
	char		**envp; */

	tmp = shell->tokens;
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void	ft_more_cmds(t_shell *shell)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
		ft_child(shell, fd);
	else
		ft_parent(shell, fd);
}
