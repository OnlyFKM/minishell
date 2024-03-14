/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:12:02 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:31:26 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_countdig(long int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*dst;
	int			numdig;
	long int	num;	

	num = n;
	if (num < 0)
		num *= -1;
	numdig = ft_countdig(num);
	if (n < 0)
		numdig++;
	dst = malloc(sizeof(char) * (numdig + 1));
	if (!dst)
		return (0);
	dst[numdig--] = '\0';
	while (numdig >= 0)
	{
		dst[numdig--] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
