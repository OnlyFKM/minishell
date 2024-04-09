/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:32:51 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/09 18:35:12 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_status_exit(t_shell *shell, int status)
{
	if (status >= 0 && status <= 125)
	{
		ft_free_exit(shell);
		ft_printf("exit\n");
		exit(status);
	}
	else
	{
		if (status < 0)
			status = 128 + (status % 128);
		else
			status = status % 256;
		ft_free_exit(shell);
		ft_printf("exit\n");
		exit(status);
	}
}

void	ft_check_number(t_shell *shell, t_tokens *tokens)
{
	t_tokens	*tmp;
	int			i;

	i = 0;
	tmp = tokens->next;
	if (tmp->str[0] == '-' || tmp->str[0] == '+')
		i++;
	while (ft_isdigit(tmp->str[i]))
		i++;
	if (tmp->str[i] == '\0')
	{
		if (!tmp->next)
			ft_status_exit(shell, ft_atoi(tmp->str));
		if (tmp->next)
			ft_printf("exit\nmarinashell: exit: too many arguments\n");
	}
	else
	{
		ft_printf("exit\n");
		ft_printf("marinashell: exit: %s: numeric argument required\n",
			tmp->str);
		ft_free_exit(shell);
		exit(255);
	}
}

void	ft_exit(t_shell *shell, t_tokens *tokens)
{
	t_tokens	*tmp;

	tmp = tokens;
	if (tokens == NULL || !tmp->next)
	{
		ft_free_exit(shell);
		ft_printf("exit\n");
		rl_clear_history(); //maybe
		exit(EXIT_SUCCESS);
	}
	else
		ft_check_number(shell, tokens);
}

void	ft_pwd(t_shell *shell)
{
	shell->status = 0;
	ft_printf("%s\n", shell->pwd);
}
