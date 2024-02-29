/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:47:21 by frcastil          #+#    #+#             */
/*   Updated: 2024/02/06 11:32:30 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_gnl(const char *s, int c)
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

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (free(s1), s1 = NULL, NULL);
	}
	if (!s2)
		return (NULL);
	dst = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!dst)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		dst[i] = s1[i];
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (free(s1), s1 = NULL, dst);
}
