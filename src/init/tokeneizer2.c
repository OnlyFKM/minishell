/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeneizer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:17:25 by yfang             #+#    #+#             */
/*   Updated: 2024/03/05 16:43:16 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_redirections(t_shell *shell, int *i)
{
	int	j;

	j = 0;
	while (shell->line[*i] && shell->line[*i] != '|')
	{
		(*i)++;
		j++;
	}
	return (j);
}

int	ft_redirectiontype(char *start)
{
	if (*start == '<')
	{
		if (ft_strncmp(start, "<<", 2) == 0)
			return (INSOURCE);
		else
			return (IN);
	}
	else
	{
		if (ft_strncmp(start, ">>", 2) == 0)
			return (APPEND);
		else
			return (OUT);
	}
}

void	ft_token_redirections(t_shell *shell, int *i)
{
	char	*tmp;
	char	*start;
	int		j;

	start = shell->line + *i;
	j = ft_redirections(shell, i);
	tmp = ft_strndup(start, j);
	ft_init_token(shell, ft_redirectiontype(start), tmp);
	free(tmp);
}
