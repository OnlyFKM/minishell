/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:30:41 by frcastil          #+#    #+#             */
/*   Updated: 2023/04/24 16:58:15 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*des_ptr;
	unsigned char	*src_ptr;

	des_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (dst > src)
		while (len--)
			des_ptr[len] = src_ptr[len];
	else
		while (len--)
			*des_ptr++ = *src_ptr++;
	return (dst);
}
/*
int	main(void)
{
	char	dst[] = "Insertar frase";
	char	src[] = "";

	ft_memmove(dst, src, 12);
	printf("%s", dst);
	return(0);
}
*/
