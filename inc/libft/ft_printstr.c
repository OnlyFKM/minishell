/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:35:02 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/06 11:27:12 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		c += ft_printchar(str[i]);
		i++;
	}
	return (c);
}
