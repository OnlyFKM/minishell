/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:52:49 by frcastil          #+#    #+#             */
/*   Updated: 2024/04/12 18:08:28 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_error(t_shell *shell)
{
	if (shell->error == 1)
		ft_printf("marinashell: error for quotes not closed\n");
	if (shell->error == 2)
		ft_printf("marinashell: syntax error near unexpected token '<'\n");
	if (shell->error == 3)
		ft_printf("marinashell: syntax error near unexpected token '>'\n");
	if (shell->error == 4)
	{
		ft_printf("marinashell: syntax error near ");
		ft_printf("unexpected token 'newline'\n");
	}
	if (shell->error == 5)
		ft_printf("marinashell: syntax error near unexpected token '|'\n");
	if (shell->error == 6)
		ft_printf("marinashell: error opening file\n");
	if (shell->error == 7)
		ft_printf("marinashell: syntax error near unexpected token\n");
	if (shell->error == 8)
		ft_printf("marinashell: failure in pipe or fork\n");
	if (shell->error == 10)
		ft_printf("marinashell: syntax error not an ascii char\n");
	shell->status = 1;
}

void	ft_welcome(void)
{
	ft_printf("\n░██╗░░░░░░░██╗███████╗██╗░░░░░░█████╗░░█████╗░███╗░░░███╗");
	ft_printf("███████╗  ████████╗░█████╗░\n");
	ft_printf("░██║░░██╗░░██║██╔════╝██║░░░░░██╔══██╗██╔══██╗████╗░████║");
	ft_printf("██╔════╝  ╚══██╔══╝██╔══██╗\n");
	ft_printf("░╚██╗████╗██╔╝█████╗░░██║░░░░░██║░░╚═╝██║░░██║██╔████╔██║");
	ft_printf("█████╗░░  ░░░██║░░░██║░░██║\n");
	ft_printf("░░████╔═████║░██╔══╝░░██║░░░░░██║░░██╗██║░░██║██║╚██╔╝██║");
	ft_printf("██╔══╝░░  ░░░██║░░░██║░░██║\n");
	ft_printf("░░╚██╔╝░╚██╔╝░███████╗███████╗╚█████╔╝╚█████╔╝██║░╚═╝░██║");
	ft_printf("███████╗  ░░░██║░░░╚█████╔╝\n");
	ft_printf("░░░╚═╝░░░╚═╝░░╚══════╝╚══════╝░╚════╝░░╚════╝░╚═╝░░░░░╚═╝");
	ft_printf("╚══════╝  ░░░╚═╝░░░░╚════╝░\n");
	ft_printf("\n");
	ft_printf("███╗░░░███╗░█████╗░██████╗░██╗███╗░░██╗░█████╗░░░██╗░██████╗");
	ft_printf("██╗░░██╗░░██╗███████╗██╗░░░░░██╗░░░░░\n");
	ft_printf("████╗░████║██╔══██╗██╔══██╗██║████╗░██║██╔══██╗░██╔╝██╔════╝");
	ft_printf("╚██╗░██║░░██║██╔════╝██║░░░░░██║░░░░░\n");
	ft_printf("██╔████╔██║███████║██████╔╝██║██╔██╗██║███████║██╔╝░╚█████╗");
	ft_printf("░░╚██╗███████║█████╗░░██║░░░░░██║░░░░░\n");
	ft_printf("██║╚██╔╝██║██╔══██║██╔══██╗██║██║╚████║██╔══██║╚██╗░░╚═══██╗");
	ft_printf("░██╔╝██╔══██║██╔══╝░░██║░░░░░██║░░░░░\n");
	ft_printf("██║░╚═╝░██║██║░░██║██║░░██║██║██║░╚███║██║░░██║░╚██╗██████╔╝");
	ft_printf("██╔╝░██║░░██║███████╗███████╗███████╗\n");
	ft_printf("╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░╚═╝░░╚═╝╚═════╝");
	ft_printf("░╚═╝░░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝\n\n");
}
