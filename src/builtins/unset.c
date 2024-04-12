/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:46:23 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 18:37:01 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_unset_loop(t_shell *shell, t_tokens *tokens)
{
	t_tokens	*tmp;

	tmp = tokens;
	while (tmp)
	{
		ft_unset(shell, tmp->str);
		tmp = tmp->next;
	}
}

void	ft_unset_two(t_shell *shell, t_env *tmp, char *str)
{
	if (ft_strcmp(shell->env->name, str) == EXIT_SUCCESS)
	{
		tmp = shell->env;
		shell->env = shell->env->next;
		free(tmp->name);
		free(tmp->content);
		free(tmp);
	}
}

void	ft_unset(t_shell *shell, char *str)
{
	t_env	*tmp;
	t_env	*aux;

	tmp = NULL;
	ft_unset_two(shell, tmp, str);
	tmp = shell->env;
	aux = tmp->next;
	while (aux)
	{
		if (ft_strcmp(aux->name, str) == EXIT_SUCCESS)
		{
			tmp->next = aux->next;
			free(aux->name);
			free(aux->content);
			free(aux);
		}
		else
			tmp = tmp->next;
		aux = tmp->next;
	}
	shell->status = 0;
}
