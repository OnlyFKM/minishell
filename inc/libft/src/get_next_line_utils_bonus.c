/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:04:12 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:33:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc2(size_t count, size_t size)
{
	char	*pnt;
	size_t	i;

	i = 0;
	pnt = malloc(count * size);
	if (!pnt)
		return (0);
	while (i < count * size)
		pnt[i++] = '\0';
	return (pnt);
}

int	ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	len = (ft_strlen2((char *)s1, 0) + ft_strlen2((char *)s2, 0));
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	ft_strlen2(const char *a, int b)
{
	size_t	len;

	len = 0;
	if (b == 0)
	{
		while (a[len] != '\0')
			len++;
	}
	if (b == '\n')
	{
		while (a[len] != '\n' && a[len] != '\0')
			len++;
		if (a[len] == '\n')
			len++;
	}
	return (len);
}
