/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agroup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:07:28 by yfang             #+#    #+#             */
/*   Updated: 2024/03/19 16:13:57 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_tokentype(int type)
{
	if (type > 4 && type < 10)
		return (1);
	return (0);
}

/* void	ft_agroup_pipes(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;
	char		*str;

	tmp = shell->tokens;
	aux = tmp->next;
	while (aux)
	{
		if (!ft_tokentype(aux->type))
		{
			str = ft_strdup(tmp->str);
			free(tmp->str);
			tmp->str = ft_strjoin_space(str, aux->str);
			free(str);
			tmp->next = aux->next;
			free(aux->str);
			free(aux);
		}
		else
			tmp = tmp->next->next;
		aux = tmp->next;
	}
} */

/* void	ft_agroup_pipes(t_shell *shell)
{
	t_tokens	*aux;
	t_cmd		*tmp;
	char		*str;

	aux = shell->tokens;
	tmp = shell->cmd;
	while (aux)
	{
		if (!ft_tokentype(aux->type))
		{
			str = ft_strdup(aux->str);
			free(tmp->str);
			tmp->str = ft_strjoin_space(str, aux->str);
			free(str);
			tmp->next = aux->next;
			free(aux->str);
			free(aux);
		}
		else
			tmp = tmp->next->next;
		aux = tmp->next;
	}
} */

void	ft_agroup(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;
	char		*str;

	tmp = shell->tokens;
	aux = tmp->next;
	while (aux)
	{
		if (aux->space == 1)
		{
			str = ft_strdup(tmp->str);
			free(tmp->str);
			tmp->str = ft_strjoin(str, aux->str);
			free(str);
			tmp->next = aux->next;
			free(aux->str);
			free(aux);
		}
		else
			tmp = tmp->next;
		aux = aux->next;
	}
}
