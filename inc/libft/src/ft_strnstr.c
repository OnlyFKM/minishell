/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:17:16 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:32:59 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;
	int	j;

	if (to_find[0] == '\0' || (len == 0 && !str))
		return ((char *)str);
	i = 0;
	while (str[i] != '\0' && (size_t)i < len)
	{
		j = 0;
		while (to_find[j] != '\0' && (size_t)i + j < len)
		{
			if (str[i + j] == to_find[j])
				j++;
			else
				break ;
		}
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (0);
}
