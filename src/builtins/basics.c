/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:32:51 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 22:00:52 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_status_exit(t_shell *shell, t_tokens *tokens, long status)
{
	if (status >= 0 && status <= 125)
	{
		ft_free_exit(shell);
		ft_printf("exit\n");
		shell->status = status;
		exit(status);
	}
	else
	{
		if (status > MAX || status < MIN)
			ft_printf("marinashell: exit: %s: numeric argument required\n",
				tokens->str);
		if (status < 0)
			shell->status = 128 + (status % 128);
		else
			shell->status = status % 256;
		ft_free_exit(shell);
		ft_printf("exit\n");
		exit(shell->status);
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
			ft_status_exit(shell, tmp, ft_atol(tmp->str));
		if (tmp->next)
			ft_printf("exit\nmarinashell: exit: too many arguments\n");
	}
	else
	{
		ft_printf("exit\nmarinashell: exit: %s: numeric argument required\n",
			tmp->str);
		shell->status = 255;
		ft_free_exit(shell);
		exit(255);
	}
}

void	ft_exit(t_shell *shell, t_tokens *tokens)
{
	t_tokens	*tmp;

	tmp = tokens;
	if (tmp == NULL)
	{
		ft_free_exit(shell);
		ft_printf("exit\n");
		shell->status = 0;
		exit(EXIT_SUCCESS);
	}
	else if (!tmp->next)
	{
		ft_free_exit(shell);
		ft_printf("exit\n");
		shell->status = 0;
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
