/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:03:58 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/06 11:27:14 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunsigned(unsigned int nb)
{
	int	c;

	c = 0;
	if (nb >= 10)
		c += ft_printunsigned(nb / 10);
	ft_printchar(nb % 10 + '0');
	c++;
	return (c);
}
