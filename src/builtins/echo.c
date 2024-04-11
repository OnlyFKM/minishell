/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:48:30 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/11 19:47:38 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_print_echo(t_tokens *check, int flag)
{
	while (check)
	{
		if (check && check->next)
		{
			while (check && check->next)
			{
				ft_printf("%s", check->str);
				ft_printf(" ");
				check = check->next;
			}
		}
		if (flag == 0)
			ft_printf("%s\n", check->str);
		if (flag > 0)
			ft_printf("%s", check->str);
		break ;
	}
}

int	ft_check_n(t_tokens *check)
{
	int	i;

	if (ft_strncmp(check->str, "-n\0", 3) == 0)
		return (1);
	else if (ft_strncmp(check->str, "-n", 2) == 0)
	{
		i = 1;
		while (check->str[i] == 'n')
			i++;
		if (check->str[i] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}

void	ft_echo(t_shell *shell, t_tokens *list)
{
	int			nb;
	t_tokens	*check;

	nb = 0;
	check = list;
	if (!check->next)
		ft_printf("\n");
	else
	{
		check = check->next;
		while (check)
		{
			if (ft_check_n(check) == 1)
				nb++;
			else
				break ;
			check = check->next;
		}
		ft_print_echo(check, nb);
	}
	shell->status = 0;
}
