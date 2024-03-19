/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftplus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:18:54 by yfang             #+#    #+#             */
/*   Updated: 2024/03/19 10:43:31 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_strjoin_space(char const *s1, char const *s2)
{
	char	*dst;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = malloc(sizeof(char) * (len1 + len2) + 2);
	if (!dst)
		return (0);
	len1++;
	dst[len1 + len2] = '\0';
	while (len2-- > 0)
		dst[len1 + len2] = s2[len2];
	dst[--len1] = ' ';
	while (len1-- > 0)
		dst[len1] = s1[len1];
	return (dst);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*d;
	size_t	len;

	len = ft_strlen(s);
	if (len < n)
		n = len;
	d = (char *)malloc(n + 1);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, n);
	d[n] = '\0';
	return (d);
}
