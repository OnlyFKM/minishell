/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:56:49 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/29 13:02:11 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_append_node(t_tokens **head, char *str, int n_words)
{
	t_tokens	*new_node;
	t_tokens	*last;

	new_node = ft_calloc(1, sizeof(t_prueba));
	new_node->str = str;
	new_node->n_words = n_words;
	new_node->count_cmd = 0;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_node;
	}
}

void	ft_create_node(t_shell *shell, t_tokens **head, char *start,
		int len)
{
	char	*token_copy;

	token_copy = ft_calloc(len + 1, sizeof(char));
	ft_strlcpy(token_copy, start, len + 1);
	ft_append_node(head, token_copy, shell->tokens->n_words++);
}

void	ft_tokenize_string(t_shell *shell, char *str, t_tokens **head)
{
	char	*token_start;
	char	*token_end;
	int		token_len;

	token_start = str;
	token_end = str;
	while (*token_end)
	{
		ft_skip_special_chars(&token_start);
		ft_find_token_end(&token_start, &token_end);
		token_len = token_end - token_start;
		if (token_len > 0)
			ft_create_node(shell, head, token_start, token_len);
		token_start = token_end;
	}
}

t_tokens	*ft_tokenize(t_shell *shell, char *str)
{
	t_tokens	*head;

	head = ft_initialize_list();
	ft_tokenize_string(shell, str, &head);
	return (head);
}
