/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:16:46 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/28 16:12:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Preguntar a Fer si va a poner si cada cosa es un argumento o no

void	ft_check_builtings(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if (ft_strncmp(tmp->str, "pwd\0", 4) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(shell->tokens->str, "echo\0", 5) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(shell->tokens->str, "env\0", 4) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(shell->tokens->str, "exit\0", 5) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(shell->tokens->str, "unset\0", 6) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(shell->tokens->str, "export\0", 7) == EXIT_SUCCESS)
			tmp->type = 0;
		else if (ft_strncmp(shell->tokens->str, "cd\0", 3) == EXIT_SUCCESS)
			tmp->type = 0;
		else
			tmp->type = 1;
		if (tmp->next)
			tmp = tmp->next;
		break ;
	}
}

void	ft_count_cmd(t_shell *shell)
{
	t_tokens	*tmp;

	tmp = shell->tokens;
	while (tmp)
	{
		if ((tmp->type == 0) || (tmp->type == 1))
			shell->count_cmd++;
		if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
}

int	ft_first_equal(char *str)
{
	char	*tmp;
	int		i;

	tmp = str;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == '=')
			break ;
		i++;
	}
	return (i);
}

int	ft_special_char(char sp)
{
	return (sp == ' ' || sp == '\'' || sp == '\"' || sp == '>' || sp == '<'
		|| sp == '|');
}

int	ft_whitespace(char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\r'
			&& *str != '\f' && *str != '\v')
			return (EXIT_SUCCESS);
		str++;
	}
	return (EXIT_FAILURE);
}

/* NOTAS
\t: Representa un carácter de tabulación.
\n: Representa un carácter de nueva línea.
\r: Representa un carácter de retorno de carro (retorno al principio de la línea)
\f: Representa un carácter de avance de página.
\v: Representa un carácter de tabulación vertical. */