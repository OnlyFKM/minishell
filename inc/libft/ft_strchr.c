/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:49:39 by frcastil          #+#    #+#             */
/*   Updated: 2023/08/25 16:11:01 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!str)
		return (0);
	while (*str != (char) c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (1);
}

/* int	main(void)
{
	char	*str;
	char	c;

	c = 'o';
	str = "Hello, World";
	printf("%s", ft_strchr(str, c));
	return (0);
} */