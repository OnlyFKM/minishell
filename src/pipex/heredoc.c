/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:53 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/29 15:06:48 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* void	ft_heredoc(t_shell *shell)
{
	t_tokens	*del;
	char		*input;
	char		*line;
	int			output;

	input = ft_calloc(1, sizeof(char *));
	del = shell->tokens;
	while (1)
	{
		line = get_next_line(0);
		if (ft_strcmp(line, del->str))
		{
			free(line);
			break ;
		}
		input = ft_strdup(line);
		free(line);
	}
} */

void	ft_do_heredoc(char	*input)
{
	int	fd_here[2];
	int	pid;

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

void	ft_heredoc(t_shell *shell, char *limiter)
{
	char	*line;
	char	*input;
	int		output;

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
}

// probar que ese sea el delimitador o split

void	ft_pipex(t_shell *shell, t_tokens *tokens)
{
	t_tokens	*tmp;

	tmp = tokens;
	if (tmp->heredoc != 0)
		ft_heredoc(shell, tmp->next->str);
	if (tmp->outfile != -1)
	{
		dup2(tmp->outfile, STDOUT_FILENO);
		close(tmp->outfile);
	}
	if (tmp->infile != -1)
	{
		dup2(tmp->infile, STDIN_FILENO);
		close(tmp->infile);
	}
}
