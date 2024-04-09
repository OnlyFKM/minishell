/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:48:44 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/09 16:47:07 by frcastil         ###   ########.fr       */
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
		tmp[i] = ft_strjoin_2(join, "=");
		join = tmp[i];
		tmp[i] = ft_strjoin_2(join, aux->content);
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
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, "PATH") == EXIT_SUCCESS)
			break ;
		tmp = tmp->next;
	}
	splitted = ft_split(tmp->content, ':');
	while (splitted[++i])
	{
		result = ft_strjoin(splitted[i], cmd);
		if (access(result, F_OK) == EXIT_SUCCESS)
			return (ft_free_double(splitted), result);
		free(result);
	}
	ft_free_double(splitted);
	return (NULL);
}

void	ft_execve_two(t_shell *shell, char **str, char **envp)
{
	int		pid;

	pid = fork();
	if (pid == 0)
		execve(shell->path, str, envp);
	else
		waitpid(pid, NULL, 0);
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
	cmd = ft_strjoin_2(aux, str[0]);
	envp = NULL;
	envp = ft_update_envp(shell);
	shell->path = ft_find_path(shell, cmd);
	if (shell->path != NULL)
		ft_execve_two(shell, str, envp);
	else
	{
		ft_printf("marinashell: %s: command not found\n", str[0]);
		shell->status = 127;
	}
	ft_free_execve(str, envp, cmd, shell->path);
}
