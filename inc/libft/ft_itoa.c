/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:51:01 by frcastil          #+#    #+#             */
/*   Updated: 2023/05/10 17:23:57 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count(long int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	n_copy;
	int			n_len;

	n_copy = n;
	if (n_copy < 0)
		n_copy *= -1;
	n_len = ft_count(n_copy);
	if (n < 0)
		n_len++;
	str = malloc((n_len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str [n_len--] = '\0';
	while (n_len >= 0)
	{
		str[n_len--] = (n_copy % 10) + '0';
		n_copy /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
