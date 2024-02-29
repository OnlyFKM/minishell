/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:08:59 by frcastil          #+#    #+#             */
/*   Updated: 2023/05/12 16:24:34 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s ||!f)
		return (0);
	i = ft_strlen(s);
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s[i])
	{
		str [i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
