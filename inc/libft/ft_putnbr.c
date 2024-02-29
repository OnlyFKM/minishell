/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:40:48 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/06 11:27:22 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
	{
		c += ft_printchar('-');
		c += ft_printchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		c += ft_printchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		c += ft_printchar(n + '0');
	else
	{
		c += ft_putnbr(n / 10);
		c += ft_putnbr(n % 10);
	}
	return (c);
}
