/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:07:06 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:06 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*rest_dst;
	const char	*rest_src;

	rest_dst = (char *)dst;
	rest_src = (const char *)src;
	if (!len || dst == src)
		return (dst);
	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len--)
			rest_dst[len] = rest_src[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
