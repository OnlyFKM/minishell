/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:59:27 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/29 13:01:23 by frcastil         ###   ########.fr       */
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
	shell->tokens = ft_calloc(1, sizeof(t_tokens));
	//shell->prueba = ft_calloc(1, sizeof(t_prueba));
	if (!shell || !shell->tokens || !shell->env)
		return (EXIT_FAILURE);
	shell->line = NULL;
	shell->tmp_cd = NULL;
	shell->tokens->count_cmd = 0;
	//shell->count_cmd = 0;
	ft_dupenvp(shell, envp);
	ft_env(shell->env, shell->envp);
	ft_first_pwd(shell);
	shell->tokens->n_words = 0;
	return (EXIT_SUCCESS);
}
