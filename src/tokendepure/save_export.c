/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:13:01 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 18:34:41 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_onlyexport(t_tokens *token)
{
	t_tokens	*tmp;

	tmp = token;
	while (tmp && tmp->type != PIPE)
		tmp = tmp->next;
	if (tmp)
		return (0);
	else
		return (1);
}

void	ft_saveexport(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (!ft_strncmp(tmp->str, "export\0", 7) && ft_onlyexport(tmp))
			ft_copytoken(tmp, shell);
		tmp = tmp->next;
	}
}
