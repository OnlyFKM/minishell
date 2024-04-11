/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:16:51 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/11 19:01:32 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_tokensize(t_tokens *lst)
{
	int			i;
	t_tokens	*cplst;

	if (!lst)
		return (0);
	i = 1;
	cplst = lst;
	while (cplst->next)
	{
		i++;
		cplst = cplst->next;
	}
	return (i);
}

t_env	*ft_nodelast(t_env *env)
{
	t_env	*current;

	if (!env)
		return (0);
	current = env;
	while (current->next)
		current = current->next;
	return (current);
}

void	ft_nodeadd_back(t_env **env, t_env *new)
{
	t_env	*current;

	if (*env != 0)
	{
		current = ft_nodelast(*env);
		current->next = new;
	}
	else
		*env = new;
}

int	ft_nodesize(t_env *env)
{
	int		i;
	t_env	*current;

	if (!env)
		return (0);
	i = 1;
	current = env;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (i);
}
