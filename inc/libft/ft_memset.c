/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:56:07 by frcastil          #+#    #+#             */
/*   Updated: 2023/04/24 16:58:20 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;

	ptr = b;
	while (len)
	{
		*(ptr++) = (unsigned char)c;
		len--;
	}
	return (b);
}
/*
int	main(void)
{
	char	str[] = "Hello world";

	ft_memset(str, '4', 5);
	printf("%s", str);
	return (0);
}
*/