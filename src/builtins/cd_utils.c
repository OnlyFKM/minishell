/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:54:35 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/04 12:20:26 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_change_pwd(t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "PWD") == EXIT_SUCCESS)
		{
			if (tmp->content)
				free(tmp->content);
			tmp->content = ft_strdup(shell->tmp_cd);
			if (tmp->content)
			{
				free(shell->pwd);
				shell->pwd = ft_strdup(shell->tmp_cd);
			}
			if (!tmp->content)
				return ;
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_oldpwd(t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "OLDPWD") == 0)
		{
			if (tmp->content)
				free(tmp->content);
			tmp->content = ft_strdup(shell->pwd);
			if (!tmp->content)
				return ;
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_search_dir(t_shell *shell, char *find)
{
	t_env	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, find) == 0)
		{
			if (shell->tmp_cd)
				free(shell->tmp_cd);
			shell->tmp_cd = ft_strdup(tmp->content);
			if (!shell->tmp_cd)
				return ;
			break ;
		}
		tmp = tmp->next;
	}
}
