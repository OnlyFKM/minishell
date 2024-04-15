/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:00:15 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/15 11:34:51 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_free_exit(t_shell *shell)
{
	ft_free_double(shell->envp);
	ft_free_env(shell->env);
	ft_free_tokens(&shell->tokens);
	free(shell->line);
	free(shell->pwd);
	if (shell->path != NULL)
		free(shell->path);
	shell->path = NULL;
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

void	ft_free_tokens(t_tokens **tokens)
{
	t_tokens	*current;
	t_tokens	*tmp;

	current = *tokens;
	while (current)
	{
		tmp = current->next;
		if (current->str)
			free(current->str);
		if (current->path)
		{
			free(current->path);
			current->path = NULL;
		}
		current->str = NULL;
		free(current);
		current = NULL;
		current = tmp;
	}
}
