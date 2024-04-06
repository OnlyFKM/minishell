
#include "../../inc/minishell.h"

//sigint (signal interrupt) 
void	ft_sigint(int signum)
{
	g_signal = signum;
	ft_printf("signal es %d\n", g_signal);
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

// EOF (end of file)
void	ft_eof(int signum)
{
	g_signal = signum;
	ft_printf("Exiting marinashell...\n");
	rl_clear_history();
	exit(0);
}
