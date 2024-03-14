/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:59:27 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/07 16:02:54 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_first_pwd(t_shell *shell)
{
	char	buffer[256];

	shell->pwd = ft_strdup(getcwd(buffer, sizeof(buffer)));
}

int	ft_init(t_shell *shell, char **envp)
{
	shell->env = ft_calloc(1, sizeof(t_env));
	shell->tokens = NULL;
	if (!shell || !shell->env)
		return (EXIT_FAILURE);
	shell->line = NULL;
	shell->tmp_cd = NULL;
	shell->count_cmd = 0;
	ft_dupenvp(shell, envp);
	ft_env(shell->env, shell->envp);
	ft_first_pwd(shell);
	return (EXIT_SUCCESS);
}
