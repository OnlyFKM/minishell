/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeneizer2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:17:25 by yfang             #+#    #+#             */
/*   Updated: 2024/04/11 19:57:16 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_redirections(t_shell *shell, int *i)
{
	int	j;

	j = 0;
	while (shell->line[*i] && ft_ifredi(shell->line[*i]))
	{
		(*i)++;
		j++;
	}
	while (shell->line[*i] && shell->line[*i] == ' ')
	{
		(*i)++;
		j++;
	}
	while (shell->line[*i] && !ft_isspecial(shell->line[*i]))
	{
		(*i)++;
		j++;
	}
	return (j);
}

int	ft_redirectiontype(char *start)
{
	if (ft_strncmp(start, "<<", 2) == 0)
		return (HERE_DOC);
	else if (ft_strncmp(start, "<", 1) == 0)
		return (IN);
	else if (ft_strncmp(start, ">>", 2) == 0)
		return (APPEND);
	else
		return (OUT);
}

int	ft_redierror(t_tokens *token, int i, int j, char c)
{
	if (token->str[i] == '\0')
		return (4);
	if (c == '<')
	{
		if (ft_ifredi(token->str[j]) || j == 3)
			if (j == 3 || token->str[j] != c)
				return (2);
	}
	else if (c == '>')
	{
		if (ft_ifredi(token->str[j]) || j == 3)
			if (j == 3 || token->str[j] != c)
				return (3);
	}
	if (ft_strlen(token->str) < 4)
		return (12);
	return (0);
}

int	ft_checkredi(t_tokens *token)
{
	int		i;
	char	c;
	int		j;

	i = 0;
	c = token->str[i];
	j = 0;
	while (token->str[i] && j <= 3 && token->str[i] == c)
	{
		i++;
		j++;
	}
	return (ft_redierror(token, i, j, c));
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
	if (ft_checkredi(ft_lasttoken(shell->tokens)) != 0)
		shell->error = ft_checkredi(ft_lasttoken(shell->tokens));
}
