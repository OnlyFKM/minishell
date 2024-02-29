/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:16:51 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/13 10:18:42 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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

void	ft_nodeadd_back(t_env *env, t_env *new)
{
	t_env	*current;

	if (env == NULL)
		env = new;
	else
	{
		current = ft_nodelast(env);
		current->next = new;
	}
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
