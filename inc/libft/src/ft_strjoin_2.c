/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:22:38 by frcastil          #+#    #+#             */
/*   Updated: 2024/03/19 14:23:43 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin_2(char *s1, char *s2)
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
