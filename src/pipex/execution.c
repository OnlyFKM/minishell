/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:07:30 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/06 17:56:40 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* void	ft_process(char *path, char **str, char **envp)
{
	pid_t	pid;
	int		status;
	int		fd;

	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		fd = open("/fd", O_WRONLY);
		if (fd == -1)
			exit(EXIT_FAILURE);
		if (dup2(fd, STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		if (execve(path, str, envp) == -1)
			ft_printf("marinashell: %s: command not found!\n", str[0]);
		exit (EXIT_FAILURE);
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
			exit(EXIT_FAILURE);
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

// REMINDER -- When I printf the Command not found I must return 127 --

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
	ft_process(path, str, envp);
	//execve(path, str, envp);
	if (str != NULL)
		ft_free_double(str);
	ft_free_double(envp);
	if (cmd != NULL)
		free(cmd);
	if (path != NULL)
		free(path);
}

void	ft_execve_one(t_shell *shell)
{
	char	**str;
	int		pid;

	str = ft_pointer_str(shell);
	pid = fork();
	if (pid == 0)
	{
		ft_execve(shell);
		ft_printf("marinashell: %s: command not found!\n", str[0]);
		exit (127);
	}
	else
		waitpid(pid, NULL, 0);
	free(str);
} */

/* void	ft_do_execve(t_shell *shell, t_tokens *tokens, int flag)
{
	char	*cmd;
	char	*aux;
	char	**str;
	char	**envp;
	char	*cmd;
	char	*aux;
	char	**str;
	char	*cmd;
	char	*aux;
	char	**str;
	int		pid;

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
/* int	ft_check_path(t_shell *shell, t_tokens *tokens)
{
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
} */
