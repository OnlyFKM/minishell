/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:48:44 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/19 17:31:35 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* char	**ft_pointer_str(t_shell *shell)
{
	t_tokens	*aux;
	char		**tmp;
	int			i;
	int			len;

	i = 0;
	aux = shell->tokens;
	len = ft_tokensize(aux);
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
		result = ft_strjoin_2(splitted[i], cmd);
		if (access(result, F_OK) == EXIT_SUCCESS)
			return (result);
		i++;
	}
	return (NULL);
}

void	ft_do_execve(t_shell *shell, int flag)
{
	char	*path;
	char	*cmd;
	char	*aux;
	char	**str;
	char	**envp;

	if (flag == 0)
	{
		cmd = ft_strdup("/");
		aux = cmd;
		cmd = ft_strjoin_2(aux, shell->tokens->str);
		path = ft_find_path(shell, cmd);
		str = ft_pointer_str(shell);
		envp = ft_update_envp(shell);
		if (path)
			shell->status = execve(path, str, envp);
	}
	if (flag == 1)
		ft_free_execve(str, envp, cmd, path);
}

int	ft_check_path(t_shell *shell)
{
	char	*path;
	char	*cmd;
	char	*aux;

	cmd = ft_strdup("/");
	aux = cmd;
	cmd = ft_strjoin_2(aux, shell->tokens->str);
	path = ft_find_path(shell, cmd);
	free(cmd);
	if (!path)
		return (EXIT_FAILURE);
	free(path);
	return (EXIT_SUCCESS);
}
void	ft_execve_one(t_shell *shell)
{
	int		pid;
	char	**str;

	if (ft_check_path(shell) == EXIT_SUCCESS)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_do_execve(shell, 0);
			ft_do_execve(shell, 1);
			exit(127);
		}
		else
		{
			waitpid(pid, &shell->status, 0);
		}
	}
	else
	{
		str = ft_pointer_str(shell);
		ft_printf("marinashell: %s: command not found\n", str[0]);
		if (str)
			ft_free_double(str);
	}
} */
