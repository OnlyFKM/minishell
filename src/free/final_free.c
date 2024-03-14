/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:22:28 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/14 16:02:05 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_free_exit(t_shell *shell)
{
	ft_free_double(shell->envp);
	ft_free_env(shell->env);
	ft_prueba(&shell->tokens);
	free(shell->line);
	free(shell->pwd);
	free(shell);
}

void	ft_free_env(t_env *env)
{
	t_env	*current;
	t_env	*tmp;

	current = env;
	while (current)
	{
		if (current->name)
			free(current->name);
		if (current->content)
			free(current->content);
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

void	ft_free_double(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
