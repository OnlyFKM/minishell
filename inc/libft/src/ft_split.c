/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:06:22 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:30 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_numworld(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (i);
}

size_t	ft_wlen(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_free(char **dst, int j)
{
	while (j-- > 0)
		free(dst[j]);
	free(dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = malloc(sizeof(char *) * (ft_numworld(s, c) + 1));
	if (!dst)
		return (0);
	while (j < ft_numworld(s, c))
	{
		while (s[i] == c)
			i++;
		dst[j] = ft_substr(s, i, ft_wlen(s, c, i));
		if (!(dst[j]))
		{
			ft_free(dst, j);
			return (0);
		}
		i += (int)ft_wlen(s, c, i);
		j++;
	}
	dst[j] = 0;
	return (dst);
}
