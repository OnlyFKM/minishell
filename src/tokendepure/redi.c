/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:25:14 by yfang             #+#    #+#             */
/*   Updated: 2024/04/11 12:57:31 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_isredi(int c)
{
	if (c >= OUT && c <= HERE_DOC)
		return (1);
	return (0);
}

char	*ft_takename(t_tokens *redi)
{
	char	*file;
	int		i;

	i = 0;
	while (redi->str[i]
		&& (ft_ifredi(redi->str[i]) || ft_isspace(redi->str[i])))
		i++;
	file = ft_strdup(redi->str + i);
	return (file);
}

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
	shell->flag = 1;
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

void	ft_redi(t_tokens *cmd, t_tokens *redi, t_shell *shell)
{
	int	fd;

	if (redi->type == OUT)
		ft_out(cmd, redi, shell);
	else if (redi->type == APPEND)
		ft_out(cmd, redi, shell);
	else if (redi->type == IN)
		ft_in(cmd, redi, shell);
	else
	{
		if (cmd)
			cmd->infile = ft_heredoc(cmd, redi, shell);
		else
		{
			fd = ft_heredoc(cmd, redi, shell);
			close(fd);
			shell->error = 9;
		}
	}
}

void	ft_removeredi(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;
	int			i;

	tmp = shell->tokens;
	i = 0;
	while (tmp && ft_isredi(tmp->type))
	{
		aux = tmp->next;
		free(tmp->str);
		tmp->str = NULL;
		free(tmp);
		tmp = aux;
	}
	shell->tokens = tmp;
	if (aux)
		aux = tmp->next;
	while (aux)
	{
		if (ft_isredi(aux->type))
		{
			tmp->next = aux->next;
			free(aux->str);
			aux->str = NULL;
			free(aux);
		}
		else
			tmp = tmp->next;
		ft_printf("%s, %i\n", aux->str, aux->space);
		aux = tmp->next;
		if (aux && i != 0)
			aux->space = 1;
		if (i == 0 && tmp->type != PIPE)
			i = 1;
	}
	ft_agroup(shell);
}

void	ft_changetype(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (shell->cmdflag == 0)
		{
			tmp->type = 1;
			shell->cmdflag = 1;
		}
		if (tmp->type == PIPE)
			shell->cmdflag = 0;
		tmp = tmp->next;
	}
	shell->cmdflag = 0;
}

void	ft_quitredi(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;

	tmp = shell->tokens;
	while (tmp)
	{
		aux = tmp;
		while (aux && ft_isredi(aux->type) && aux->type != PIPE)
			aux = aux->next;	
		while (tmp && tmp->type != PIPE)
		{
			if (ft_isredi(tmp->type))
				ft_redi(aux, tmp, shell);
			if (!aux)
				shell->error = 9;
			tmp = tmp->next;
		}
		if (tmp)
			tmp = tmp->next;
	}
	ft_removeredi(shell);
	ft_changetype(shell);
}
