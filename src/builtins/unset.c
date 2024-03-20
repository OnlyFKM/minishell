/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:46:23 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/19 14:26:22 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_unset_loop(t_shell *shell, t_tokens *prueba)
{
	t_tokens	*tmp;

	tmp = prueba;
	while (tmp)
	{
		ft_unset(shell, tmp->str);
		tmp = tmp->next;
	}
}

void	ft_unset(t_shell *shell, char *str)
{
	t_env	*current;
	t_env	*prev;

	current = shell->env;
	while (current->next)
	{
		if (ft_strcmp(current->name, str) == EXIT_SUCCESS)
		{
			if (prev)
				prev->next = current->next;
			else
				shell->env = current->next;
			if (current->name)
				free(current->name);
			if (current->content)
				free(current->content);
			if (current)
				free(current);
		}
		prev = current;
		current = current->next;
	}
}
