/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:36:08 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:45 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = malloc(sizeof(char) * (len1 + len2) + 1);
	if (!dst)
		return (0);
	dst[len1 + len2] = '\0';
	while (len2-- > 0)
		dst[len1 + len2] = s2[len2];
	while (len1-- > 0)
		dst[len1] = s1[len1];
	return (dst);
}
