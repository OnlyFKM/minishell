/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeredi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:21:59 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 19:02:11 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_miniagroup_two(t_tokens *tmp, t_tokens *aux)
{
	char	*str;

	str = ft_strdup(tmp->str);
	free(tmp->str);
	tmp->str = ft_strjoin(str, aux->str);
	free(str);
	tmp->next = aux->next;
	free(aux->str);
	free(aux);
}

void	ft_miniagroup_one(t_tokens *aux, t_tokens *tmp)
{
	t_tokens	*cmd;

	while (aux)
	{
		cmd = tmp;
		while (cmd && ft_isredi(cmd->type) && cmd->type != PIPE)
			cmd = cmd->next;
		while (aux && aux->type != PIPE)
		{
			if (aux->space == 1)
				ft_miniagroup_two(tmp, aux);
			else
				tmp = tmp->next;
			aux = aux->next;
			if (tmp->type == PIPE)
				tmp = tmp->next;
		}
		if (aux)
			aux = aux->next;
	}
}

void	ft_miniagroup(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;

	tmp = shell->tokens;
	if (tmp)
		aux = tmp->next;
	else
		aux = NULL;
	ft_miniagroup_one(aux, tmp);
}

void	ft_miniremoveredi(t_tokens *tmp, t_tokens *aux)
{
	int	i;

	i = 0;
	while (aux)
	{
		if (ft_isredi(aux->type))
		{
			tmp->next = aux->next;
			free(aux->str);
			aux->str = NULL;
			free(aux);
		}
		else
			tmp = tmp->next;
		aux = tmp->next;
		if (aux && i != 0 && tmp->type != PIPE)
			aux->space = 1;
		if (i == 0 && tmp->type != PIPE)
			i = 1;
	}
}

void	ft_removeredi(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;

	tmp = shell->tokens;
	while (tmp && ft_isredi(tmp->type))
	{
		aux = tmp->next;
		free(tmp->str);
		tmp->str = NULL;
		free(tmp);
		tmp = aux;
	}
	shell->tokens = tmp;
	if (aux)
		aux = tmp->next;
	ft_miniremoveredi(tmp, aux);
	ft_miniagroup(shell);
}
