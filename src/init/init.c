/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:59:27 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 15:16:53 by frcastil         ###   ########.fr       */
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
	g_signal = 1;
	shell->env = NULL;
	shell->tokens = NULL;
	shell->export = NULL;
	if (!shell)
		return (EXIT_FAILURE);
	shell->line = NULL;
	shell->tmp_cd = NULL;
	shell->count_cmd = 0;
	shell->space = 0;
	shell->in = dup(STDIN_FILENO);
	shell->out = dup(STDOUT_FILENO);
	shell->status = 0;
	shell->cmdflag = 0;
	shell->error = 0;
	shell->flag = 0;
	ft_dupenvp(shell, envp);
	ft_env(shell, shell->envp);
	ft_first_pwd(shell);
	return (EXIT_SUCCESS);
}
