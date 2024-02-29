/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:15:07 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/06 11:27:03 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dtype(char const *args, int i, va_list *list)
{
	int	c;

	c = 0;
	if (args[i] == 'c')
		c += ft_printchar(va_arg(*list, int));
	else if (args[i] == 's')
		c += ft_printstr(va_arg(*list, char *));
	else if (args[i] == 'p')
		c += ft_printptr(va_arg(*list, unsigned long long));
	else if (args[i] == 'd')
		c += ft_printdec(va_arg(*list, int));
	else if (args[i] == 'i')
		c += ft_printdec(va_arg(*list, int));
	else if (args[i] == 'u')
		c += ft_printunsigned(va_arg(*list, unsigned int));
	else if (args[i] == 'x')
		c += ft_printhexa(va_arg(*list, unsigned int), 'x');
	else if (args[i] == 'X')
		c += ft_printhexa(va_arg(*list, unsigned int), 'X');
	else if (args[i] == '%')
		c += ft_printchar('%');
	return (c);
}

int	ft_printf(char const *args, ...)
{
	va_list	list;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start (list, args);
	while (args[i])
	{
		if (args[i] != '%')
			c += ft_printchar(args[i]);
		else
		{
			i++;
			c += ft_dtype(args, i, &list);
		}
		i++;
	}
	va_end (list);
	return (c);
}
