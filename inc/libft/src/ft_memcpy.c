/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:56:06 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:03 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*rest_dst;
	const char	*rest_src;
	size_t		i;

	rest_dst = (char *)dst;
	rest_src = (const char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		rest_dst[i] = rest_src[i];
		i++;
	}
	return (dst);
}
