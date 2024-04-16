/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:09:25 by yfang             #+#    #+#             */
/*   Updated: 2024/04/16 11:40:07 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_numworld_(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		i++;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
			s++;
		s++;
	}
	return (i);
}

size_t	ft_wlen_(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] && s[i] == c)
	{
		len++;
		i++;
	}
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_free_(char **dst, int j)
{
	while (j-- > 0)
		free(dst[j]);
	free(dst);
}

char	**ft_split_two(char const *s, char c)
{
	char	**dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = malloc(sizeof(char *) * (ft_numworld_(s, c) + 1));
	if (!dst)
		return (0);
	while (j < ft_numworld_(s, c))
	{
		if (s[i] == c)
			i++;
		dst[j] = ft_substr(s, i, ft_wlen_(s, c, i));
		if (!(dst[j]))
		{
			ft_free_(dst, j);
			return (0);
		}
		i += (int)ft_wlen_(s, c, i);
		j++;
	}
	dst[j] = 0;
	return (dst);
}
