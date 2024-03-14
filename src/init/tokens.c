/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:22:15 by yfang             #+#    #+#             */
/*   Updated: 2024/03/14 17:01:20 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_token(t_shell *shell, int type, char *str)
{
	t_tokens	*tmp;

	tmp = ft_newtoken(type, str);
	ft_addbacktoken(&shell->tokens, tmp);
}

void	ft_tokenizer(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->line[i])
	{
		ft_printf("%sline: %s, int i: %d%s\n", BLUE, shell->line, i, END);
		if ((!ft_isspecial(shell->line[i])))
			ft_token(shell, &i);
		else if (shell->line[i] == '\'' || shell->line[i] == '\"')
			ft_token_in_quotes(shell, &i);
		else if (shell->line[i] == '>' || shell->line[i] == '<')
			ft_token_redirections(shell, &i);
		else if (shell->line[i] == '|')
			ft_init_token(shell, PIPE, "|");
		if (shell->line[i] != '\0')	
			i++;
	}
}
