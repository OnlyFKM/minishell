/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agroup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:07:28 by yfang             #+#    #+#             */
/*   Updated: 2024/03/29 15:50:13 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_tokentype(int type)
{
	if (type == 9)
		return (1);
	return (0);
}

void	ft_quitpipes(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;

	tmp = shell->tokens;
	aux = tmp->next;
	ft_printf("pipa 3\n");
	while (aux)
	{
		if (ft_tokentype(aux->type))
		{
			tmp->next = aux->next;
			free(aux->str);
			free(aux);
		}
		else
			tmp = tmp->next->next;
		aux = tmp->next;
	}
	ft_printf("pipa 4\n");
}

void	ft_agroup_pipes(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;
	char		*str;

	tmp = shell->tokens;
	aux = tmp->next;
	ft_printf("pipa 1\n");
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
	ft_printf("pipa 2\n");
	ft_quitpipes(shell);
}

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
	ft_check_builtings(shell);
}
