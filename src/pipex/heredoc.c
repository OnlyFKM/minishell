/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:53 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/16 12:57:49 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_execve_msg(t_shell *shell, char **str)
{
	if (str[0] && !ft_strncmp(str[0], "echo\0", 5))
		ft_printf("marinashell: %s%s: command not found\n", str[0], str[1]);
	else if (ft_path(shell) == EXIT_SUCCESS)
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

int	ft_dir(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir != NULL)
	{
		closedir(dir);
		return (1);
	}
	else
		return (0);
}

int	ft_check_fullpath(t_shell *shell)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	tmp = ft_split(shell->tokens->str, ' ');
	i = 0;
	if (access(tmp[0], X_OK) == EXIT_SUCCESS && ft_dir(tmp[0]) == 0)
	{
		shell->path = ft_strdup(tmp[0]);
		ft_free_double(tmp);
		return (EXIT_SUCCESS);
	}
	if (tmp != NULL)
		ft_free_double(tmp);
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
