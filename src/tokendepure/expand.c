/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:50:32 by yfang             #+#    #+#             */
/*   Updated: 2024/03/15 17:24:24 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* void	ft_add_expand(t_tokens *token, char *str, int start, int end)
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
		if (ft_isdigit(token->str[i]))
		{
			ft_printf("is num\n");
			start = i;
			end = i;
			ft_find_and_expand(shell, token, start, end);
		}
		else if (ft_isalpha(token->str[i]))
		{
			start = i;
			ft_printf("is alpha\n");
			while (token->str[i] && ft_isalnum(token->str[i]) == 1)
				i++;
			end = i;
			ft_find_and_expand(shell, token, start, end);
		}
		i++;
	}
} */

void	ft_final_expand(t_env *env, t_tokens *token, int start, int len)
{
	char	*dst;
	int		dstlen;
	int		i;
	int		j;
	int		k;

	dstlen = ft_strlen(env->content) + (ft_strlen(token->str) - (len + 1));
	dst = ft_calloc(dstlen + 1, sizeof(char));
	i = 0;
	j = 0;
	k = 0;
	while (i < dstlen)
	{
		while (i < start - 1)
		{
			dst[i] = token->str[i];
			i++;
		}
		k = i + ft_strlen(env->name) + 2;
		while (env->content[j])
		{
			dst[i] = env->content[j];
			j++;
			i++;
		}
		dst[i] = token->str[k];
		k++;
		if (i < dstlen)
			i++;
	}
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
	while (i < dstlen)
	{
		while (i < start - 1)
		{
			dst[i] = token->str[i];
			i++;
		}
		j = i + len;
		dst[i] = token->str[j];
		j++;
		if (i < dstlen)
			i++;
	}
	dst[i] = '\0';
	free(token->str);
	token->str = dst;
}

void	ft_reemplace(char *dst, t_env *env, t_tokens *token, int start)
{
	int	flag;

	flag = 0;
	//en algun lado de este while hace segmentation fault creo que es cuando recorre la cadena entera
	while (env)
	{
		if (ft_strncmp(env->name, dst, ft_strlen(dst) + 1))
		{
			ft_final_expand(env, token, start, ft_strlen(dst));
			flag = 1;
		}
		env = env->next;
	}
	if (flag && !env)
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
			if (ft_isdigit(token->str[i]))
				dst = ft_strdup(&token->str[i]);
			else if (token->str[i] == '$')
				dst = ft_strdup("$");
			else
			{
				while (token->str[i] && ft_spandchar(token->str[i]))
				{
					i++;
					j++;
				}
				dst = ft_strndup(token->str + (i - j), j);
			}
			tmp = shell->env;
			ft_reemplace(dst, tmp, token, i - j); // segmenttion fault dentro de aqui
			free(dst);
		}
		if (token->str)
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
