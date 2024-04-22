/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:00:22 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/22 13:17:08 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/minishell.h"

void	ft_sigint(int signum)
{
	(void)signum;
	if (g_signal != 1 && g_signal != 42)
	{
		write(1, "\33[K\n", 5);
		rl_replace_line("", 0);
		g_signal = 1;
	}
	else if (g_signal == 42)
	{
		write(1, "\33[K\n", 5);
		close(0);
		g_signal = 1;
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
		write(1, "\33[K\n", 5);
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
	}
}
