/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:34:23 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:13 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putptr(unsigned long long ptr, int *len)
{
	ft_putstr("0x", len);
	ft_puthexa(ptr, 'x', len);
}

void	ft_putnbr(int nb, int *len)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', len);
		ft_putchar('2', len);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0', len);
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}

void	ft_putunsint(unsigned int i, int *len)
{
	if (i >= 10)
		ft_putunsint(i / 10, len);
	ft_putchar(i % 10 + '0', len);
}

void	ft_puthexa(unsigned long long nb, char x, int *len)
{
	if (nb >= 16)
		ft_puthexa(nb / 16, x, len);
	if (x == 'x')
		ft_putchar("0123456789abcdef"[nb % 16], len);
	else if (x == 'X')
		ft_putchar("0123456789ABCDEF"[nb % 16], len);
}
