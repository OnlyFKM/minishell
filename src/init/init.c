/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:18:27 by yfang             #+#    #+#             */
/*   Updated: 2024/03/07 16:02:54 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_init(t_shell	*shell, char **envp)
{
	(void)envp;
	shell->env = ft_calloc(1, sizeof(t_env));
	shell->tokens = NULL;
	if (!shell || /* !shell->tokens || */ !shell->env)
		return (EXIT_FAILURE);
	shell->line = NULL;
	ft_dupenvp(shell, envp);
	ft_env(shell->env, shell->envp);
	return (EXIT_SUCCESS);
}
