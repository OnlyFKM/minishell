/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:15:50 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:37 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*pnt;

	len = ft_strlen(s1);
	pnt = malloc(sizeof(char) * len + 1);
	if (!pnt)
		return (0);
	pnt[len] = '\0';
	while (len-- > 0)
		pnt[len] = s1[len];
	return (pnt);
}
