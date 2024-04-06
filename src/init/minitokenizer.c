/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:57:58 by yfang             #+#    #+#             */
/*   Updated: 2024/04/05 17:21:19 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_tokens	*ft_init_token2(t_tokens *token, int type, char *str)
{
	t_tokens	*tmp;

	tmp = ft_newtoken(type, str, 0);
	ft_addbacktoken(&token, tmp);
	return (token);
}

t_tokens	*ft_minitoken(t_tokens *tokens, char *str, int *i)
{
	char	*tmp;
	char	*start;
	int		j;

	start = str + *i;
	j = 0;
	while (str[*i] && ft_isspace(str[*i]))
	{
		(*i)++;
		j++;
	}
	while (str[*i] && !ft_isspace(str[*i]))
	{
		(*i)++;
		j++;
	}
	tmp = ft_strndup(start, j);
	if (tokens == NULL)
		tokens = ft_init_token2(tokens, CMD, tmp);
	else
		tokens = ft_init_token2(tokens, ARG, tmp);
	free(tmp);
	return (tokens);
}

t_tokens	*ft_minitokenizer(t_tokens *token, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && ft_isspace(str[i]))
			i++;
		token = ft_minitoken(token, str, &i);
		if (str[i])	
			i++;
	}
	return (token);
}
