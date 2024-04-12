/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createredi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:18:33 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 18:35:25 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_in(t_tokens *cmd, t_tokens *redi, t_shell *shell)
{
	int		fd;
	char	*file;

	file = ft_takename(redi);
	shell->flag = 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		shell->error = 6;
	if (cmd)
	{
		if (cmd->infile != 0 && cmd->type != 1)
			close(cmd->infile);
		cmd->infile = fd;
	}
	free(file);
}

void	ft_out(t_tokens *cmd, t_tokens *redi, t_shell *shell)
{
	int		fd;
	char	*file;

	file = ft_takename(redi);
	shell->flag = 1;
	if (redi->type == OUT)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd < 0)
		shell->error = 6;
	if (cmd)
	{
		if (cmd->outfile != 0)
			close(cmd->outfile);
		cmd->outfile = fd;
	}
	free(file);
}

static void	ft_heredocsoon(char *limit, int fd[2])
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = readline("> ");
		if (!line || (!ft_strncmp(limit, line, ft_strlen(limit))
				&& !ft_strncmp(limit, line, ft_strlen(line))))
			exit(EXIT_SUCCESS);
		ft_putstr_fd(line, fd[1]);
		ft_putchar_fd('\n', fd[1]);
		free(line);
		line = NULL;
	}
}

int	ft_heredoc(t_tokens *cmd, t_tokens *redi, t_shell *shell)
{
	pid_t	pid;
	int		pipefd[2];
	char	*limit;

	g_signal = 42;
	limit = ft_takename(redi);
	if (!limit)
		shell->error = 7;
	else
	{
		if (cmd && cmd->infile != 0)
			close(cmd->infile);
		if (pipe(pipefd) == -1)
			shell->error = 8;
		pid = fork();
		if (pid < 0)
			shell->error = 8;
		if (shell->error == 0 || shell->error == 9)
		{
			if (pid == 0)
				ft_heredocsoon(limit, pipefd);
			return (waitpid(-1, NULL, 0), close(pipefd[1]), pipefd[0]);
		}
	}
	return (0);
}
