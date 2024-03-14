/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:48:53 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/14 15:23:10 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* void	ft_heredoc(t_shell *shell)
{
	t_tokens	*del;
	char		*input;
	char		*line;
	int			output;

	input = ft_calloc(1, sizeof(char *));
	del = shell->tokens->next;
	line = get_next_line(0);
	while (1)
	{
		if (ft_strcmp(line, del->str))
		{
			free(line);
			break ;
		}
	}
}
 */