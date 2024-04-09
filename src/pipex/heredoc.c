/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:53 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/09 14:44:02 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

// hay alguna forma de contar si hay redirecciones o no?

void	ft_pipex(t_shell *shell, t_tokens *tokens)
{
	t_tokens	*tmp;

	(void)shell;
	tmp = tokens;
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
