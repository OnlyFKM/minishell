/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:49:59 by yfang             #+#    #+#             */
/*   Updated: 2024/02/21 14:20:42 by yfang            ###   ########.fr       */
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
	free(shell->line);
}
