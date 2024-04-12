/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:25:14 by yfang             #+#    #+#             */
/*   Updated: 2024/04/12 19:23:55 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_takename(t_tokens *redi)
{
	char	*file;
	int		i;

	i = 0;
	while (redi->str[i] && (ft_ifredi(redi->str[i])
			|| ft_isspace(redi->str[i])))
		i++;
	file = ft_strdup(redi->str + i);
	return (file);
}

void	ft_redi(t_tokens *cmd, t_tokens *redi, t_shell *shell)
{
	int	fd;

	if (redi->type == OUT)
		ft_out(cmd, redi, shell);
	else if (redi->type == APPEND)
		ft_out(cmd, redi, shell);
	else if (redi->type == IN)
		ft_in(cmd, redi, shell);
	else
	{
		if (cmd)
			cmd->infile = ft_heredoc(cmd, redi, shell);
		else
		{
			fd = ft_heredoc(cmd, redi, shell);
			close(fd);
			shell->error = 9;
		}
	}
}

void	ft_changetype(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (shell->cmdflag == 0)
		{
			tmp->type = 1;
			shell->cmdflag = 1;
		}
		if (tmp->type == PIPE)
			shell->cmdflag = 0;
		tmp = tmp->next;
	}
	shell->cmdflag = 0;
}

void	ft_quitredi(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;

	tmp = shell->tokens;
	while (tmp)
	{
		aux = tmp;
		while (aux && ft_isredi(aux->type) && aux->type != PIPE)
			aux = aux->next;
		while (tmp && tmp->type != PIPE)
		{
			if (ft_isredi(tmp->type))
				ft_redi(aux, tmp, shell);
			if (!aux)
				shell->error = 9;
			tmp = tmp->next;
		}
		if (tmp)
			tmp = tmp->next;
	}
	ft_removeredi(shell);
	ft_changetype(shell);
}
