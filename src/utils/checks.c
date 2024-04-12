/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:15:04 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 18:34:36 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_check_builtings(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp && tmp->str)
	{
		if (ft_strncmp(tmp->str, "pwd\0", 4) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(tmp->str, "echo\0", 5) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(tmp->str, "env\0", 4) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(tmp->str, "exit\0", 5) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(tmp->str, "unset\0", 6) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(tmp->str, "export\0", 7) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(tmp->str, "cd\0", 3) == EXIT_SUCCESS)
			tmp->type = 0;
		tmp = tmp->next;
	}
}

void	ft_checkpipe(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (ft_tokentype(tmp->type))
			if (!tmp->next || ft_strncmp(tmp->str, "|\0", 2))
				shell->error = 5;
		tmp = tmp->next;
	}
}

void	ft_checkascii(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->line[i])
	{
		if (!ft_isascii(shell->line[i]))
			shell->error = 10;
		i++;
	}
}
