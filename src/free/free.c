/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:00:15 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/11 14:44:32 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_prueba(t_tokens **prueba)
{
	t_tokens	*current;
	t_tokens	*tmp;

	current = *prueba;
	while (current)
	{
		tmp = current->next;
		free(current->str);
		current->str = NULL;
		free(current);
		current = NULL;
		current = tmp;
	}
}

void	ft_free_loop(t_shell *shell)
{
	ft_prueba(&shell->tokens);
	shell->tokens = NULL;
	shell->count_cmd = 0;
	free(shell->line);
}
