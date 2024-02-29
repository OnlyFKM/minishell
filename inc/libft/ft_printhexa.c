/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:58:07 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/06 11:27:06 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa(unsigned long long nb, char ch)
{
	unsigned long long	c;

	c = 0;
	if (nb >= 16)
		c += ft_printhexa(nb / 16, ch);
	if (ch == 'x')
		ft_printchar("0123456789abcdef"[nb % 16]);
	else if (ch == 'X')
		ft_printchar("0123456789ABCDEF"[nb % 16]);
	c++;
	return (c);
}
