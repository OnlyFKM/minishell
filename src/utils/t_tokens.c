/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tokens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:30:22 by yfang             #+#    #+#             */
/*   Updated: 2024/04/12 18:09:48 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_copytoken(t_tokens *token, t_shell *shell)
{
	t_tokens	*tmp;

	while (token)
	{
		tmp = ft_newcopytoken(token);
		ft_addbacktoken(&shell->export, tmp);
		token = token->next;
	}
}

t_tokens	*ft_newcopytoken(t_tokens *token)
{
	t_tokens	*tmp;

	if (!token)
		return (NULL);
	tmp = ft_calloc(1, sizeof(t_tokens));
	tmp->str = ft_strdup(token->str);
	if (token->path)
		tmp->path = ft_strdup(token->path);
	tmp->type = token->type;
	tmp->space = token->space;
	tmp->infile = token->infile;
	tmp->outfile = token->outfile;
	tmp->next = NULL;
	token = token->next;
	return (tmp);
}

t_tokens	*ft_lasttoken(t_tokens *token)
{
	t_tokens	*cptoken;

	if (!token)
		return (0);
	cptoken = token;
	while (cptoken->next)
		cptoken = cptoken->next;
	return (cptoken);
}

void	ft_addbacktoken(t_tokens **token, t_tokens *new)
{
	t_tokens	*cptoken;

	if (*token != 0)
	{
		cptoken = ft_lasttoken(*token);
		cptoken->next = new;
	}
	else
		*token = new;
}

t_tokens	*ft_newtoken(int type, char *str, int space)
{
	t_tokens	*new_token;

	new_token = ft_calloc(1, sizeof(t_tokens));
	if (!new_token)
		return (0);
	new_token->str = ft_strdup(str);
	new_token->type = type;
	new_token->space = space;
	new_token->infile = 0;
	new_token->outfile = 0;
	new_token->next = NULL;
	return (new_token);
}
