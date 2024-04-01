/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:57:03 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/29 14:45:49 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_execve(t_shell *shell, t_tokens *tokens)
{
	char	*path;
	char	*cmd;
	char	*aux;
	char	**str;
	char	**envp;

	str = ft_split(tokens->str, ' ');
	cmd = ft_strdup("/");
	aux = cmd;
	cmd = ft_strjoin_2(aux, str[0]);
	path = ft_find_path(shell, cmd);
	envp = ft_update_envp(shell);
	//ft_process(path, str, envp);
	execve(path, str, envp);
	if (str != NULL)
		ft_free_double(str);
	ft_free_double(envp);
	if (cmd != NULL)
		free(cmd);
	if (path != NULL)
		free(path);
}

void	ft_child(t_shell *shell, t_tokens *tokens, int *fd)
{
	t_tokens	*tmp;

	tmp = tokens;
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	ft_pipex(shell, tmp);
	if (tmp->type == 0)
		ft_builtins(shell, tmp->str);
	else
		ft_execve(shell, tmp);
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
		ft_pipex(shell, tmp);
		if (tmp->type == 0)
			ft_builtins(shell, tmp->str);
		else
			ft_execve_one(shell, tmp);
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
