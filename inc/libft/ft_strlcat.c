/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:23:49 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/26 09:49:38 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	while (src[src_len] != '\0' && dst_len + src_len + 1 < size)
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	if (dst_len < size)
		dst[dst_len + src_len] = '\0';
	while (src[src_len] != '\0')
		src_len++;
	return (dst_len + src_len);
}

/* int	main(void)
{
	char	dst[] = "Hello";
	char	src[] = " Fran";

	ft_strlcat(dst, src, 8);
	printf("%s\n", dst);
	return (0);
} */