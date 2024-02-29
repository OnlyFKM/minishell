/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:33:09 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:34 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!*s && (char) c == '\0')
		return ((char *) s);
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
		if (*s == (char) c)
			return ((char *) s);
	}
	return (0);
}
