/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:25:14 by yfang             #+#    #+#             */
/*   Updated: 2024/04/06 19:52:58 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_isredi(int c)
{
	if (c >= OUT && c <= HERE_DOC)
		return (1);
	return (0);
}

char	*ft_takename(t_tokens *redi)
{
	char	*file;
	int		i;

	i = 0;
	while (redi->str[i] && (ft_ifredi(redi->str[i]) || ft_isspace(redi->str[i])))
		i++;
	file = ft_strdup(redi->str + i);
	return (file);
}

void	ft_out(t_tokens *cmd, t_tokens *redi, t_shell *shell)
{
	int		fd;
	char	*file;

	file = ft_takename(redi);
	if (redi->type == OUT)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (fd < 0)
		shell->error = 6;
	cmd->outfile = fd;
	free(file);
}

void	ft_redi(t_tokens *cmd, t_tokens *redi, t_shell *shell)
{
	if (redi->type == OUT)
		ft_out(cmd, redi, shell);
	else if (redi->type == APPEND)
		ft_out(cmd, redi, shell);
	/* else if (redi->type == IN)
		ft_in(cmd, redi);
	else
		ft_here_doc(cmd, redi); */
}

void	ft_removeredi(t_shell *shell)
{
	t_tokens	*tmp;
	t_tokens	*aux;

	tmp = shell->tokens;
	while (tmp && ft_isredi(tmp->type))
	{
		aux = tmp->next;
		free(tmp->str);
		free(tmp);
		tmp = aux;
	}
	aux = tmp->next;
	while (aux)
	{
		if (ft_isredi(aux->type))
		{
			tmp->next = aux->next;
			free(aux->str);
			free(aux);
		}
		else
			tmp = tmp->next;
		aux = tmp->next;
	}
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
			tmp = tmp->next;
		}
		if (tmp)
			tmp = tmp->next;
	}
	ft_removeredi(shell);
}
