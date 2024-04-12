/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:33:00 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/11 19:46:04 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_dupenvp(t_shell *shell, char **envp)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (envp[j])
	{
		if (ft_strncmp(envp[j], "OLDPWD", 6) == EXIT_SUCCESS)
			flag++;
		j++;
	}
	shell->envp = ft_calloc(j + 1 - flag, sizeof(char *));
	j = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "OLDPWD", 6) == EXIT_SUCCESS)
			i++;
		shell->envp[j] = ft_strdup(envp[i]);
		j++;
		i++;
	}
	shell->envp[j] = NULL;
}

void	ft_print_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp->next)
	{
		if (tmp->name && tmp->content)
		{
			ft_printf("%s", tmp->name);
			ft_printf("=");
			ft_printf("%s\n", tmp->content);
		}
		tmp = tmp->next;
	}
}

t_env	*ft_newenv(char *name, char *content)
{
	t_env	*new_token;

	new_token = ft_calloc(1, sizeof(t_env));
	if (!new_token)
		return (0);
	new_token->name = ft_strdup(name);
	if (content)
		new_token->content = ft_strdup(content);
	else
		new_token->content = NULL;
	new_token->next = NULL;
	return (new_token);
}

void	ft_init_env(t_shell *shell, char *name, char *content)
{
	t_env	*tmp;

	tmp = ft_newenv(name, content);
	ft_nodeadd_back(&shell->env, tmp);
}

void	ft_env(t_shell *shell, char **envp)
{
	int		i;
	char	**splitted;

	i = 0;
	while (envp[i])
	{
		splitted = ft_split(envp[i], '=');
		if (splitted[0] && splitted[1])
			ft_init_env(shell, splitted[0], splitted[1]);
		free(splitted[0]);
		free(splitted[1]);
		free(splitted);
		i++;
	}
	shell->status = 0;
}
