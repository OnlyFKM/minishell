
#include "../../inc/minishell.h"

// str es el SPLIT

void	ft_do_execve_2(t_shell *shell, char *path)
{
	char	**str;
	char	**envp;

	/* char	*path;
	char	*cmd; */
	/* char	*aux; */
	/* cmd = ft_strdup("/");
	aux = cmd;
	cmd = ft_strjoin_2(aux, shell->tokens->str); */
	// cmd = ft_strdup(ft_union_cmd(shell));
	// ft_printf("cmd es %s\n", cmd);
	// path = ft_find_path(shell, cmd);
	str = ft_pointer_str(shell);
	envp = ft_update_envp(shell);
	// if (path)
	shell->status = execve(path, str, envp);
	ft_printf("marinashell: %s: command not found\n", str[0]);
	// ft_free_execve(str, envp, cmd, path);
	ft_free_double(str);
	ft_free_double(envp);
	free(path);
}
