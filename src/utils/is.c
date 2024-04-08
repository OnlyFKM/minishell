/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:29:07 by yfang             #+#    #+#             */
/*   Updated: 2024/04/06 19:10:08 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_ifredi(char c)
{
	return (c == '>' || c == '<');
}

int	ft_spandchar(char c)
{
	return (ft_isalnum(c) || c == '_' || c == '~');
}

int	ft_isspecial(char c)
{
	return (c == ' ' || c == '\"' || c == '\'' || c == '>' || c == '<'
		|| c == '|');
}

int	ft_isspace(int c)
{
	return (c == ' ');
}
