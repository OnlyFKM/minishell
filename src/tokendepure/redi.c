/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:25:14 by yfang             #+#    #+#             */
/*   Updated: 2024/04/05 16:34:57 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_tokens	*ft_lastarg(t_tokens *token)
{
	while (token->next || token->next->type != PIPE)
		token = token->next;
	return (token);
}

void	ft_moveredi(t_shell *shell, t_tokens *tmp, t_tokens *aux)
{
	t_tokens	*last;

	last = ft_lastarg(shell->tokens);
	aux->type = tmp->type;
	aux->next = last->next;
	last->next = aux;
	free(tmp->str);
	free(tmp);
}

void	ft_quitredi(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;
	t_tokens	*supp;

	tmp = shell->tokens;
	aux = tmp->next;
	supp = aux->next;
	while (tmp)
	{
		if (ft_ifredi(tmp->type))
			ft_moveredi(shell, tmp, aux);
		tmp = tmp->next;
	}
}

//tengo que pasar todas las redirecciones detras del comando y luego quitarlas mientras abro o cierro
