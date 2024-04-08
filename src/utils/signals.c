
#include "../../inc/minishell.h"

// sigint (signal interrupt) ctrl-C
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
		g_signal = 0;
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
