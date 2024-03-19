/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:48:44 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/19 11:00:28 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pipex(t_shell *shell)
{
	t_cmd	*tmp;

	tmp = shell->cmd;
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

char	**ft_pointer_str(t_shell *shell)
{
	t_tokens	*aux;
	char		**tmp;
	int			i;
	int			len;

	i = 0;
	aux = shell->tokens;
	len = ft_prueba_size(aux);
	tmp = ft_calloc(len, sizeof(char *));
	while (aux)
	{
		tmp[i] = ft_strdup(aux->str);
		if (aux->next)
		{
			i++;
			aux = aux->next;
		}
		else
			break ;
	}
	return (tmp);
}

char	**ft_update_envp(t_shell *shell)
{
	t_env	*aux;
	char	**tmp;
	char	*join;
	int		i;
	int		len;

	i = -1;
	aux = shell->env;
	len = ft_nodesize(aux);
	tmp = ft_calloc(len, sizeof(char *));
	while (aux->next)
	{
		tmp[++i] = ft_strdup(aux->name);
		join = tmp[i];
		tmp[i] = ft_strjoin(join, "=");
		join = tmp[i];
		tmp[i] = ft_strjoin(join, aux->content);
		if (aux->next)
			aux = aux->next;
	}
	return (tmp);
}

char	*ft_find_path(t_shell *shell, char *cmd)
{
	t_env	*tmp;
	char	**splitted;
	char	*result;
	int		i;

	tmp = shell->env;
	i = 0;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, "PATH") == EXIT_SUCCESS)
			break ;
		tmp = tmp->next;
	}
	splitted = ft_split(tmp->content, ':');
	while (splitted[i])
	{
		result = ft_strjoin(splitted[i], cmd);
		if (access(result, F_OK) == EXIT_SUCCESS)
			return (result);
		i++;
	}
	return (NULL);
}

void	ft_execve(t_shell *shell)
{
	char	*path;
	char	*cmd;
	char	*aux;
	char	**str;
	char	**envp;

	cmd = ft_strdup("/");
	aux = cmd;
	cmd = ft_strjoin(aux, shell->tokens->str);
	path = ft_find_path(shell, cmd);
	str = ft_pointer_str(shell);
	envp = ft_update_envp(shell);
	execve(path, str, envp);
	if (str != NULL)
		ft_free_double(str);
	ft_free_double(envp);
	if (cmd != NULL)
		free(cmd);
	if (path != NULL)
		free(path);
}
