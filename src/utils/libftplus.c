/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftplus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:18:54 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:23:43 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
