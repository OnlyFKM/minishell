/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:50:32 by yfang             #+#    #+#             */
/*   Updated: 2024/04/10 16:41:32 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_reemplace(char *dst, t_env *env, t_tokens *token, int start)
{
	int	flag;

	flag = 0;
	while (env->next && !flag)
	{
		if (!ft_strncmp(env->name, dst, ft_strlen(dst) + 1))
		{
			ft_final_expand(env, token, start, ft_strlen(dst));
			flag = 1;
		}
		env = env->next;
	}
	if (!flag)
		ft_disexpand(token, start, ft_strlen(dst));
}

void	ft_final_expand2(char *str, t_tokens *token, int start, int len)
{
	char	*dst;
	int		dstlen;
	int		i;
	int		j;

	dstlen = ft_strlen(str) + (ft_strlen(token->str) - (len + 1));
	dst = ft_calloc(dstlen + 1, sizeof(char));
	i = 0;
	j = 0;
	len = 0;
	while (i < start - 1)
		dst[i++] = token->str[j++];
	start = 0;
	len = i + ft_strlen(str) + 1;
	while (str[start])
		dst[i++] = str[start++];
	while (i < dstlen)
		dst[i++] = token->str[len++];
	dst[i] = '\0';
	free(token->str);
	token->str = dst;
}

void	ft_find_dollar(t_tokens *token, t_shell *shell)
{
	int		i;
	int		j;
	char	*k;
	char	*dst;
	t_env	*tmp;

	i = 0;
	k = ft_itoa(shell->status);
	while (token->str[i])
	{
		j = 0;
		if (token->str[i] == '$')
		{
			i++;
			dst = ft_createdst(token, i, j, shell->status);
			tmp = shell->env;
			if (!ft_strncmp("$", dst, ft_strlen(dst) + 1)
				|| !ft_strncmp(k, dst, ft_strlen(dst) + 1))
				ft_final_expand2(dst, token, i, ft_strlen(dst));
			else
				ft_reemplace(dst, tmp, token, i);
			free(dst);
		}
		else
			i++;
	}
	free(k);
}

void	ft_expand(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (tmp->type != SIMPLE && tmp->type != PIPE)
			ft_find_dollar(tmp, shell);
		tmp = tmp->next;
	}
}
