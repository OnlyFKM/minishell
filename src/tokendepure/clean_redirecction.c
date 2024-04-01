/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_redirecction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:39:09 by yfang             #+#    #+#             */
/*   Updated: 2024/04/01 19:32:47 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_separe_redi(t_tokens *token)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	while (token->str[i] && ft_ifredi(token->str[i]))
	{
		i++;
		j++;
	}
}

void	ft_find_redi(t_shell *shell)
{
	t_tokens *tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (tmp->type >= OUT && tmp->type <= HERE_DOC)
			ft_separe_redi(tmp);
		tmp = tmp->next;
	}
}
