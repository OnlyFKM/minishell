/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agroup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:07:28 by yfang             #+#    #+#             */
/*   Updated: 2024/03/18 19:07:08 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_agroup(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;

	tmp = shell->tokens;
	aux = tmp->next;
	while (aux)
	{
		if (aux->space == 1)
		{
			free(tmp->str);
			tmp->str = ft_strjoin(tmp->str, aux->str);
			tmp->next = aux->next;
			free(aux->str);
			free(aux);
			aux = tmp->next;
		}
		else
		{
			tmp = tmp->next;
			aux = aux->next;
		}
	}
}
