/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:09:49 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:16 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	ft_filter(char str, int *i, int *len, va_list *args)
{
	if (str == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (str == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (str == 'p')
		ft_putptr(va_arg(*args, unsigned long long), len);
	else if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (str == 'u')
		ft_putunsint(va_arg(*args, unsigned int), len);
	else if (str == 'x')
		ft_puthexa(va_arg(*args, unsigned int), 'x', len);
	else if (str == 'X')
		ft_puthexa(va_arg(*args, unsigned int), 'X', len);
	else if (str == '%')
		ft_putchar('%', len);
	else
		(*i)--;
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar((char)str[i], &len);
		else
		{
			i++;
			ft_filter(str[i], &i, &len, &args);
		}
		i++;
	}
	va_end(args);
	return (len);
}
