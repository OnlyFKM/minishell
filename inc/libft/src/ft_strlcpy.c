/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:39:59 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:49 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *rest_dst, const char *rest_src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(rest_src);
	if (dstsize > 0)
	{
		while (rest_src[i] && i < (dstsize - 1))
		{
			rest_dst[i] = rest_src[i];
			i++;
		}
		rest_dst[i] = '\0';
	}
	return (src_len);
}
