/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:12:37 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/27 15:33:05 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_add_export(t_shell *shell, char *first, char *second)
{
	t_env	*last;

	last = ft_nodelast(shell->env);
	ft_create_node_env(last);
	last->name = ft_strdup(first);
	if (second == NULL)
		last->content = NULL;
	else
		last->content = ft_strdup(second);
}

void	ft_check_start(t_shell *shell, char *first, char *second)
{
	int	i;

	if ((ft_isalpha_char(first[0]) == 1) || (first[0] == '_'))
	{
		i = 0;
		while (first[i])
		{
			if (ft_isalnum(first[i]) == EXIT_FAILURE)
			{
				while (ft_isalnum(first[i]) == EXIT_FAILURE)
					i++;
			}
			if (first[i] == '\0')
				ft_add_export(shell, first, second);
			else
				break ;
		}
	}
	else
		ft_printf("marinashell: export: '%s': not a valid identifier\n", first);
}

void	ft_order_export(char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = *str;
	while (tmp[j])
		j++;
	while (i < j && str[i + 1])
	{
		if (ft_strcmp(str[i], str[i + 1]) > 0)
		{
			tmp = str[i];
			str[i] = str[i + 1];
			str[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	ft_print_export(str);
	ft_free_double(str);
}

void	ft_print_export(char **export)
{
	int	i;

	i = 0;
	while (export[i])
	{
		ft_printf("declare -x %s\n", export[i]);
		i++;
	}
}
