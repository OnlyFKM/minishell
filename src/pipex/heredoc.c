/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:53 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/08 17:19:16 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_do_heredoc(char *input)
{
	int			fd_here[2];
	int			pid;

	pipe(fd_here);
	pid = fork();
	if (pid == 0)
	{
		close(fd_here[0]);
		dup2(fd_here[1], STDOUT_FILENO);
		close(fd_here[1]);
		write(fd_here[1], input, ft_strlen(input));
	}
	else if (pid > 0)
	{
		close(fd_here[1]);
		dup2(fd_here[0], STDIN_FILENO);
		close(fd_here[0]);
		waitpid(pid, NULL, 0);
	}
}

/* void	ft_heredoc(t_shell *shell, char *limiter)
{
	char	*line;
	char	*input;
	int		output;

	g_signal = 42;
	input = ft_strdup("");
	dup2(shell->in, STDIN_FILENO);
	output = dup(STDOUT_FILENO);
	dup2(shell->out, STDOUT_FILENO);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, limiter))
			exit (1);
		input = ft_strdup(line);
		free(line);
		line = get_next_line(0);
	}
	ft_do_heredoc(input);
	dup2(output, STDOUT_FILENO);
	close(output);
	free(input);
	free(line);
} */
void	ft_heredoc(t_shell *shell, char *limiter)
{
	char	*line;
	char	*input;
	int		input_fd;
	int		output_fd;

	g_signal = 42;
	input_fd = dup(STDIN_FILENO);
	output_fd = dup(STDOUT_FILENO);
	dup2(shell->in, STDIN_FILENO);
	dup2(shell->out, STDOUT_FILENO);
	input = ft_strdup("");
	line = get_next_line(0);
	while (line && ft_strcmp(line, limiter) != 0)
	{
		input = ft_strjoin(input, line);
		free(line);
		line = get_next_line(0);
	}
	ft_do_heredoc(input);
	dup2(input_fd, STDIN_FILENO);
	dup2(output_fd, STDOUT_FILENO);
	close(input_fd);
	close(output_fd);
	free(input);
	free(line);
}

// hay alguna forma de contar si hay redirecciones o no?

void	ft_pipex(t_shell *shell, t_tokens *tokens)
{
	t_tokens	*tmp;

	(void)shell;
	tmp = tokens;
	if (tmp->heredoc != 0 && shell->flag >= 1)
		ft_heredoc(shell, tmp->next->str);
	if (tmp->outfile != -1 && shell->flag >= 1)
	{
		dup2(tmp->outfile, STDOUT_FILENO);
		close(tmp->outfile);
	}
	if (tmp->infile != -1 && shell->flag >= 1)
	{
		dup2(tmp->infile, STDIN_FILENO);
		close(tmp->infile);
	}
}
