/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:33:00 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/07 16:01:53 by yfang            ###   ########.fr       */
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

void	ft_create_node_env(t_env *env)
{
	t_env	*new_node;

	new_node = ft_calloc(1, sizeof(t_env));
	if (new_node == NULL)
		ft_printf("Error calloc env\n");
	new_node->content = NULL;
	new_node->name = NULL;
	new_node->next = NULL;
	ft_nodeadd_back(env, new_node);
}

void	ft_env(t_env *env, char **envp)
{
	int		i;
	t_env	*tmp;
	char	**splitted;

	i = 0;
	tmp = env;
	while (envp[i])
	{
		splitted = ft_split(envp[i], '=');
		if (splitted[0] && splitted[1])
		{
			tmp->name = ft_strdup(splitted[0]);
			tmp->content = ft_strdup(splitted[1]);
		}
		free(splitted[0]);
		free(splitted[1]);
		free(splitted);
		ft_create_node_env(tmp);
		tmp = tmp->next;
		i++;
	}
}
