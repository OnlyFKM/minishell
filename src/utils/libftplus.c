/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftplus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:18:54 by yfang             #+#    #+#             */
/*   Updated: 2024/04/12 18:25:26 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_ifspace(t_shell *shell, int i)
{
	if (ft_isspace(shell->line[i]))
		shell->space = 0;
	else
		shell->space = 1;
}

char	*ft_strjoin_space(char *s1, char *s2)
{
	char	*dst;
	int		len1;
	int		len2;

	if (!s1)
		s1 = calloc(1, 1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != 0)
		dst = malloc(sizeof(char) * (len1 + len2) + 2);
	else
		dst = malloc(sizeof(char) * (len1 + len2) + 1);
	if (!dst)
		return (0);
	if (len1 != 0)
		len1++;
	dst[len1 + len2] = '\0';
	while (len2-- > 0)
		dst[len1 + len2] = s2[len2];
	if (len1 != 0)
		dst[--len1] = ' ';
	while (len1-- > 0)
		dst[len1] = s1[len1];
	free(s1);
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
