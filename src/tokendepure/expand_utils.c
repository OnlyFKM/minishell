/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:25:13 by yfang             #+#    #+#             */
/*   Updated: 2024/03/27 15:49:42 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_final_expand(t_env *env, t_tokens *token, int start, int len)
{
	char	*dst;
	int		dstlen;
	int		i;
	int		j;

	dstlen = ft_strlen(env->content) + (ft_strlen(token->str) - (len + 1));
	dst = ft_calloc(dstlen + 1, sizeof(char));
	i = 0;
	j = 0;
	len = 0;
	while (i < start - 1)
		dst[i++] = token->str[j++];
	start = 0;
	len = i + ft_strlen(env->name) + 1;
	while (env->content[start])
		dst[i++] = env->content[start++];
	while (i < dstlen)
		dst[i++] = token->str[len++];
	dst[i] = '\0';
	free(token->str);
	token->str = dst;
}

void	ft_disexpand(t_tokens *token, int start, int len)
{
	char	*dst;
	int		dstlen;
	int		i;
	int		j;

	dstlen = ft_strlen(token->str) - len;
	dst = ft_calloc(dstlen + 1, sizeof(char));
	i = 0;
	while (i < start - 1)
	{
		dst[i] = token->str[i];
		i++;
	}
	while (i < dstlen)
	{
		j = i + len + 1;
		dst[i] = token->str[j];
		j++;
		if (i < dstlen)
			i++;
	}
	dst[i] = '\0';
	free(token->str);
	token->str = dst;
}

char	*ft_createdst(t_tokens *token, int i, int j)
{
	char	*dst;
	int		k;
	int		l;

	if (ft_isdigit(token->str[i]))
	{
		ft_printf("%c\n", token->str[i]);
		dst = ft_strdup(&token->str[i]);
		ft_printf("%c\n", token->str[i]);
	}
	else if (token->str[i] == '$')
		dst = ft_strdup("$");
	else
	{
		while (token->str[i] && ft_spandchar(token->str[i]))
		{
			i++;
			j++;
		}
		k = i;
		l = j;
		dst = ft_strndup(token->str + (k - l), l);
	}
	return (dst);
}
