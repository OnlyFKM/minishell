/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:48:44 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/03 16:02:23 by frcastil         ###   ########.fr       */
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
		{
			ft_free_double(splitted);
			return (result);
		}
		free(result);
	}
	return (NULL);
}

/* void	ft_do_execve(t_shell *shell, t_tokens *tokens, int flag)
{
	char	*cmd;
	char	*aux;
	char	**str;
	char	**envp;

	if (flag == 0)
	{
		str = ft_split(tokens->str, ' ');
		cmd = ft_strdup("/");
		aux = cmd;
		cmd = ft_strjoin_2(aux, str[0]);
		envp = ft_update_envp(shell);
		if (tokens->path)
			shell->status = execve(tokens->path, str, envp);
	}
	if (flag == 1)
		ft_free_execve(str, envp, cmd);
} */

int	ft_check_path(t_shell *shell, t_tokens *tokens)
{
	char	*cmd;
	char	*aux;
	char	**str;

	str = ft_split(tokens->str, ' ');
	cmd = ft_strdup("/");
	aux = cmd;
	cmd = ft_strjoin(aux, str[0]);
	free(aux);
	shell->tokens->path = ft_strdup(ft_find_path(shell, cmd));
	free(cmd);
	ft_free_double(str);
	if (!tokens->path)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	ft_execve_one(t_shell *shell, t_tokens *tokens)
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
	envp = NULL;
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
			waitpid(pid, NULL, 0);
	}
	ft_free_execve(str, envp, cmd);
}

/* void	ft_execve_one(t_shell *shell, t_tokens *tokens)
{
	int		pid;
	char	**str;

	if (ft_check_path(shell, tokens) == EXIT_SUCCESS)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_do_execve(shell, tokens, 0);
			exit(127);
		}
		else
		{
			if (shell->path)
				free(shell->path);
			waitpid(pid, NULL, 0);
		}
	}
	else
	{
		str = ft_split(tokens->str, ' ');
		ft_printf("marinashell: %s: command not found\n", str[0]);
		if (str)
			ft_free_double(str);
	}
} */
