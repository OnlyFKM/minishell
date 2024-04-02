/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:57:03 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/02 12:50:21 by frcastil         ###   ########.fr       */
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
	execve(path, str, envp);
	ft_printf("marinashell: %s: command not found!\n", str[0]);
	exit(127);
}

void	ft_child(t_shell *shell, t_tokens *tokens, int *fd)
{
	t_tokens	*tmp;

	tmp = tokens;
	close(fd[0]);
	ft_printf("fd0 %d\n", fd[0]);
	ft_printf("fd1 %d\n", fd[1]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	//ft_pipex(shell, tokens);
	if (tokens->type == 0)
		ft_builtins(shell, tokens->str);
	else
		ft_execve(shell, tokens);
	exit (0);
}

void	ft_parent(t_shell *shell, t_tokens *tokens, int *fd, int pid)
{
	t_tokens	*tmp;

	tmp = tokens;
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if (tokens->next != NULL && tokens->type != 8)
		waitpid(pid, NULL, 0);
	tmp = tokens->next;
	if (tmp->next != NULL)
		ft_more_cmds(shell, tmp);
	else
	{
		//ft_pipex(shell, tmp);
		if (tmp->type == 0)
			ft_builtins(shell, tmp->str);
		else
			ft_execve_one(shell, tmp);
	}
}

/* void	ft_final_execve(t_shell *shell, t_tokens *tokens, int *fd)
{
	int		pid;
	char	**str;
	char	**envp;
	char	*cmd;
	char	*aux;

	str = ft_split(tokens->str, ' ');
	cmd = ft_strdup("/");
	aux = cmd;
	cmd = ft_strjoin_2(aux, str[0]);
	shell->path = ft_find_path(shell, cmd);
	if (shell->path != NULL)
	{
		pid = fork();
		envp = ft_update_envp(shell);
		if (pid == 0)
		{
			execve(shell->path, str, envp);
			ft_printf("marinashell: %s: command not found\n", str[0]);
			exit(127);
		}
		else
		{
			if (shell->path)
				free(shell->path);
			waitpid(pid, NULL, 0);
		}
	}
} */


void	ft_more_cmds(t_shell *shell, t_tokens *tokens)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	ft_printf("pipe fd0 %d\n", fd[0]);
	ft_printf("pipe fd1 %d\n", fd[1]);
	pid = fork();
	if (pid < 0)
	{
		ft_printf("marinashell: error in pid\n");
		exit (EXIT_FAILURE);
	}
	else if (pid == 0)
		ft_child(shell, tokens, fd);
	else
		ft_parent(shell, tokens, fd, pid);
}
