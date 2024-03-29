/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:37:35 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/28 17:39:51 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_create_pointers_2(t_shell *shell, char *str, int j)
{
	char	*tmp;
	char	*first;
	char	*second;
	int		i;
	int		len;

	tmp = str;
	i = ft_first_equal(tmp);
	len = ft_strlen(tmp);
	first = ft_calloc(i + 1, sizeof(char *));
	second = ft_calloc(len - i + 1, sizeof(char *));
	ft_strlcpy(first, tmp, i + 1);
	while (i < len)
	{
		second[j] = tmp[i + 1];
		j++;
		i++;
	}
	if (ft_check_export(shell->env, first, second) == 1)
		ft_check_start(shell, first, second);
	if (first != NULL)
		free(first);
	if (second != NULL)
		free(second);
}

void	ft_create_pointers(t_shell *shell, char *str)
{
	char	*tmp;
	char	*first;
	char	*second;
	int		i;
	int		len;

	tmp = str;
	i = ft_first_equal(tmp);
	len = ft_strlen(tmp);
	if (i == len)
	{
		first = ft_calloc(i + 1, sizeof(char *));
		ft_strlcpy(first, tmp, i + 1);
		second = NULL;
		if (ft_check_export(shell->env, first, second) == 1)
			ft_check_start(shell, first, second);
		if (first != NULL)
			free(first);
		if (second != NULL)
			free(second);
	}
	else
		ft_create_pointers_2(shell, str, 0);
}

int	ft_check_export(t_env *env, char *first, char *second)
{
	t_env	*list;

	list = env;
	while (list->next)
	{
		if (ft_strcmp(first, list->name) == 0)
		{
			if (list->content != NULL)
				free(list->content);
			if (second != NULL)
				list->content = ft_strdup(second);
			return (EXIT_SUCCESS);
		}
		list = list->next;
	}
	return (EXIT_FAILURE);
}

void	ft_create_export(t_env *env)
{
	int		i;
	int		j;
	char	**str;
	t_env	*tmp;
	char	*aux;

	i = ft_nodesize(env);
	j = 0;
	tmp = env;
	str = ft_calloc(i, sizeof(char *));
	while (j < i - 1)
	{
		str[j] = ft_strdup(tmp->name);
		aux = str[j];
		str[j] = ft_strjoin_2(aux, "=\"");
		aux = str[j];
		if (tmp->content)
			str[j] = ft_strjoin_2(aux, tmp->content);
		aux = str[j];
		str[j] = ft_strjoin_2(aux, "\"");
		tmp = tmp->next;
		j++;
	}
	ft_order_export(str);
}

void	ft_export(t_shell *shell, t_tokens *tokens)
{
	t_tokens	*tmp;

	if (tokens->next == NULL)
		ft_create_export(shell->env);
	else
	{
		tmp = tokens->next;
		while (tmp)
		{
			if (tmp->str != NULL)
				ft_create_pointers(shell, tmp->str);
			tmp = tmp->next;
		}
	}
}
