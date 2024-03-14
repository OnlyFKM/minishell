/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:21:01 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/29 13:01:45 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_prueba_size(t_tokens *prueba)
{
	int			i;
	t_tokens	*current;

	if (!prueba)
		return (0);
	i = 1;
	current = prueba;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (i);
}

t_tokens	*ft_initialize_list(void)
{
	return (NULL);
}

void	ft_skip_special_chars(char **start)
{
	while (ft_special_char(**start))
		(*start)++;
}

void	ft_find_token_end(char **start, char **end)
{
	*end = *start;
	while (!ft_special_char(**end) && **end)
		(*end)++;
}
