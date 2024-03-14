/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:50:32 by yfang             #+#    #+#             */
/*   Updated: 2024/03/13 19:14:45 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_add_expand(t_tokens *token, char *str, int start, int end)
{
	int		i;
	int		j;
	char	*dst;
	int		strlen;

	i = 0;
	j = 0;
	strlen = ft_strlen(token->str) + ft_strlen(str) - (end - start);
	dst = ft_calloc(strlen + 1, sizeof(char *));
	end++;
	while (i < strlen)
	{
		if (i < start)
			dst[i] = token->str[i];
		else if (i >= start && str[j] != '\0')
			while (str[j] != '\0')
				dst[i++] = str[j++];
		else if (str[j] == '\0' && token->str[end] != '\0')
			dst[i] = token->str[end++];
		i++;
	}
	dst[i] = '\0';
	free(token->str);
	token->str = dst;
}

void	ft_disexpand(t_tokens *token, int start, int end)
{
	char	*dst;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(token->str) - (end - start);
	dst = ft_calloc(len + 1, sizeof (char *));
	end++;
	while (i < len)
	{
		if (i < start)
			dst[i] = token->str[i];
		else if (i >= start)
			dst[i] = token->str[end++];
		i++;
	}
	dst[i] = '\0';
	free(token->str);
	token->str = dst;
}

void	ft_find_and_expand(t_shell *shell, t_tokens *token, int start, int end)
{
	t_env	*tmp;
	char	*save;

	tmp = shell->env;
	while (tmp)
	{
		save = ft_substr(token->str, start, end - start);
		if (ft_strncmp(tmp->name, save, end - start) == 0)
		{
			ft_add_expand(token, tmp->content, start - 1, end);
		}
		else if (tmp->next == NULL)
			ft_disexpand(token, start - 1, end);
		free(save);
		tmp = tmp->next;
	}
}

void	ft_find_dollar(t_shell *shell, t_tokens *token)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	while (token->str[i] && token->str[i] != '$')
	{
		i++;
		if (ft_isdigit(token->str[i]) == 1)
		{
			start = i;
			end = i;
			ft_find_and_expand(shell, token, start, end);
		}
		else if (ft_isalpha(token->str[i]))
		{
			start = i;
			while (token->str[i] && ft_isalnum(token->str[i]) == 1)
				i++;
			end = i;
			ft_find_and_expand(shell, token, start, end);
		}
	}
}

void	ft_expand(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp != 0)
	{
		if (tmp->type != SIMPLE && tmp->type != PIPE)
		{
			ft_find_dollar(shell, tmp);
		}
		tmp = tmp->next;
	}
}
