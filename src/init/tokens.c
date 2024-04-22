/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:22:15 by yfang             #+#    #+#             */
/*   Updated: 2024/04/22 13:04:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_token(t_shell *shell, int type, char *str)
{
	t_tokens	*tmp;

	tmp = ft_newtoken(type, str, shell->space);
	ft_addbacktoken(&shell->tokens, tmp);
}

void	ft_check_error(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;

	if (shell->tokens)
		aux = ft_lasttoken(shell->tokens);
	else
		aux = NULL;
	shell->space = 0;
	ft_init_token(shell, PIPE, "|");
	tmp = ft_lasttoken(shell->tokens);
	if (aux)
	{
		if (ft_isredi(aux->type) && shell->error == 4)
			shell->error = 5;
	}
	else
	{
		if (!aux)
			shell->error = 5;
	}
}

void	ft_tokenizer(t_shell *shell)
{
	int	i;

	i = 0;
	shell->space = 0;
	while (shell->line[i])
	{
		if ((!ft_isspecial(shell->line[i])))
			ft_token(shell, &i);
		ft_ifspace(shell, i - 1);
		if (shell->line[i] == '\'' || shell->line[i] == '\"')
			ft_token_in_quotes(shell, &i);
		ft_ifspace(shell, i - 1);
		if (shell->line[i] == '>' || shell->line[i] == '<')
			ft_token_redirections(shell, &i);
		ft_ifspace(shell, i - 1);
		if (shell->line[i] == '|')
			ft_check_error(shell);
		if (shell->line[i])
			i++;
		ft_ifspace(shell, i - 1);
	}
}
