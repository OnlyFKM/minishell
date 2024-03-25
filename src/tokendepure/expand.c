/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:50:32 by yfang             #+#    #+#             */
/*   Updated: 2024/03/22 13:08:54 by yfang            ###   ########.fr       */
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

void	ft_find_dollar(t_tokens *token, t_shell *shell)
{
	int		i;
	int		j;
	char	*dst;
	t_env	*tmp;

	i = 0;
	while (token->str[i])
	{
		j = 0;
		if (token->str[i] == '$')
		{
			i++;
			dst = ft_createdst(token, i, j);
			tmp = shell->env;
			ft_reemplace(dst, tmp, token, i);
			free(dst);
		}
		else
			i++;
	}
}

void	ft_expand(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (tmp->type != SIMPLE && tmp->type != PIPE)
		{
			ft_find_dollar(tmp, shell);
		}
		tmp = tmp->next;
	}
}
