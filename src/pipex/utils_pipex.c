/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:48:44 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/15 12:57:51 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
		tmp[i] = ft_strjoin_two(join, "=");
		join = tmp[i];
		tmp[i] = ft_strjoin_two(join, aux->content);
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
	i = -1;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "PATH") == EXIT_SUCCESS)
			break ;
		tmp = tmp->next;
	}
	splitted = ft_split(tmp->content, ':');
	while (splitted[++i])
	{
		if (!cmd)
			result = ft_strjoin(splitted[i], "/");
		else
			result = ft_strjoin(splitted[i], cmd);
		if (access(result, F_OK) == EXIT_SUCCESS && cmd)
			return (ft_free_double(splitted), result);
		free(result);
	}
	return (ft_free_double(splitted), NULL);
}

void	ft_execve_two(t_shell *shell, char **str, char **envp)
{
	int		pid;

	str[0] = ft_strdup(shell->path);
	pid = fork();
	if (pid == 0 && str != NULL)
		shell->status = execve(shell->path, str, envp);
	else
		waitpid(pid, NULL, 0);
	g_signal = 1;
}

void	ft_execve_one(t_shell *shell, t_tokens *tokens)
{
	char	**str;
	char	**envp;
	char	*cmd;
	char	*aux;

	g_signal = 0;
	str = ft_split(tokens->str, ' ');
	cmd = ft_strdup("/");
	aux = cmd;
	cmd = ft_strjoin_two(aux, str[0]);
	envp = NULL;
	envp = ft_update_envp(shell);
	if (ft_path(shell) == EXIT_SUCCESS)
	{
		if (ft_check_fullpath(shell) == EXIT_FAILURE)
			shell->path = ft_find_path(shell, cmd);
	}
	if (shell->path != NULL)
		ft_execve_two(shell, str, envp);
	else
		ft_execve_msg(shell, str);
	ft_free_execve(str, envp, cmd, shell->path);
}
