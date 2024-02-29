/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:22:34 by frcastil          #+#    #+#             */
/*   Updated: 2023/05/12 17:16:07 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if (!s || ft_strlen(s) <= start)
	{
		dst = malloc(1);
		if (!dst)
			return (NULL);
		dst[0] = '\0';
		return (dst);
	}
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	dst = malloc(len + 1);
	if (!dst)
		return (0);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
