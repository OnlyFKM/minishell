/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:58:50 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/04 12:23:45 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_check_oldpwd(t_shell *shell)
{
	t_env	*tmp;

	tmp = shell->env;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, "OLDPWD") == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_first_cd(t_shell *shell)
{
	t_env	*last;

	last = ft_nodelast(shell->env);
	ft_create_node_env(last);
	last->name = ft_strdup("OLDPWD");
	last->content = ft_strdup(shell->pwd);
}

void	ft_cd_next(t_shell *shell)
{
	t_tokens	*tmp;
	int			flag;
	char		cwd[256];

	tmp = shell->tokens->next;
	flag = chdir(tmp->str);
	getcwd(cwd, sizeof(cwd));
	if (flag == -1)
		ft_printf("marinashell: cd: %s: No such file or directory\n", tmp->str);
	else if (flag == 0)
	{
		ft_oldpwd(shell);
		/* if (shell->tmp_cd != NULL)
			free(shell->tmp_cd); */
		shell->tmp_cd = ft_strdup(cwd);
		ft_change_pwd(shell);
	}
}

void	ft_cd(t_shell *shell)
{
	int	flag;

	flag = ft_check_oldpwd(shell);
	if (flag == 0)
		ft_first_cd(shell);
	if (!shell->tokens->next)
	{
		ft_search_dir(shell, "HOME");
		ft_oldpwd(shell);
		chdir(shell->tmp_cd);
		ft_change_pwd(shell);
	}
	else if (ft_strcmp(shell->tokens->next->str, "-") == 0)
	{
		ft_search_dir(shell, "OLDPWD");
		ft_oldpwd(shell);
		chdir(shell->tmp_cd);
		ft_change_pwd(shell);
		ft_pwd(shell);
	}
	else
		ft_cd_next(shell);
	if (shell->tmp_cd != NULL)
		free(shell->tmp_cd);
	shell->tmp_cd = NULL;
}
