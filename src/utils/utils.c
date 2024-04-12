/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:16:46 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 18:16:35 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_count_cmd(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if ((tmp->type == 0) || (tmp->type == 1))
			shell->count_cmd++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
}

int	ft_first_equal(char *str)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '=')
			break ;
		i++;
	}
	return (i);
}

int	ft_special_char(char sp)
{
	return (sp == ' ' || sp == '\'' || sp == '\"' || sp == '>' || sp == '<'
		|| sp == '|');
}

int	ft_whitespace(char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r'
			&& *str != '\f' && *str != '\v')
			return (EXIT_SUCCESS);
		str++;
	}
	return (EXIT_FAILURE);
}
