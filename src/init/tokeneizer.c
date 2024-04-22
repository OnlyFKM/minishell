/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeneizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:40:13 by yfang             #+#    #+#             */
/*   Updated: 2024/04/22 13:11:35 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_quoteserror(t_shell *shell, int *i, int j)
{
	if (j == 0)
	{
		if (shell->line[*i] != '\'')
			shell->error = 1;
	}
	else
		if (shell->line[*i] != '\"')
			shell->error = 1;
}

int	ft_quotes(t_shell *shell, int *i)
{
	int	j;

	j = 0;
	if (shell->line[*i] == '\'')
	{
		(*i)++;
		while (shell->line[*i] && shell->line[*i] != '\'')
		{
			(*i)++;
			j++;
		}
		ft_quoteserror(shell, i, 0);
	}
	else if (shell->line[*i] == '\"')
	{
		(*i)++;
		while (shell->line[*i] && shell->line[*i] != '\"')
		{
			(*i)++;
			j++;
		}
		ft_quoteserror(shell, i, 1);
	}
	return (j);
}

void	ft_token_in_quotes(t_shell *shell, int *i)
{
	char	*tmp;
	char	*start;
	int		j;

	start = shell->line + *i;
	j = ft_quotes(shell, i);
	tmp = ft_strndup(start + 1, j);
	if (*start == '\'')
		ft_init_token(shell, SIMPLE, tmp);
	else if (*start == '\"')
		ft_init_token(shell, DOUBLE, tmp);
	free(tmp);
}

int	ft_type(t_tokens *token)
{
	t_tokens	*tmp;

	tmp = ft_lasttoken(token);
	return (tmp->type);
}

void	ft_token(t_shell *shell, int *i)
{
	char		*tmp;
	t_tokens	*aux;
	char		*start;
	int			j;

	start = shell->line + *i;
	j = 0;
	aux = NULL;
	if (shell->tokens)
		aux = ft_lasttoken(shell->tokens);
	while (shell->line[*i] && !ft_isspecial(shell->line[*i]))
	{
		(*i)++;
		j++;
	}
	tmp = ft_strndup(start, j);
	if (aux && aux->type == PIPE)
		shell->space = 0;
	if (shell->tokens == NULL || ft_type(ft_lasttoken(shell->tokens)) == 9)
		ft_init_token(shell, CMD, tmp);
	else
		ft_init_token(shell, ARG, tmp);
	free(tmp);
}
