/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:24:05 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/14 15:26:12 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char x)
{
	if (x >= '0' && x <= '9')
		return (1);
	else
		return (0);
}
/*
int	main(void)
{
	printf("%i", ft_isdigit('a'));
	return(0);
}
*/