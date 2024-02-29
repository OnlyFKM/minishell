/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:18:06 by frcastil          #+#    #+#             */
/*   Updated: 2023/12/13 09:43:16 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(count * size);
	if (!mem)
		return (0);
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}
