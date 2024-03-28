/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:57:58 by yfang             #+#    #+#             */
/*   Updated: 2024/03/28 14:48:11 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_token(t_tokens *token, int type, char *str)
{
	t_tokens	*tmp;

	tmp = ft_newtoken(type, str, 0);
	ft_addbacktoken(&token, tmp);
}

void	ft_minitoken(t_tokens *tokens, char *str, int *i)
{
	char	*tmp;
	char	*start;
	int		j;

	start = str + *i;
	j = 0;
	while (str[*i] && !ft_isspace(str[*i]))
	{
		(*i)++;
		j++;
	}
	tmp = ft_strndup(start, j);
	if (tokens == NULL)
		ft_init_token(tokens, CMD, tmp);
	else
		ft_init_token(tokens, ARG, tmp);
	free(tmp);
}

void	ft_minitokenizer(t_tokens *token, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((!ft_isspace(str[i])))
			ft_minitoken(token, str, &i);
		if (str[i])	
			i++;
	}
}
