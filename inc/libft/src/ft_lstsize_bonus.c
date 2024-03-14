/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:25:01 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:31:55 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*cplst;

	if (!lst)
		return (0);
	i = 1;
	cplst = lst;
	while (cplst->next)
	{
		i++;
		cplst = cplst->next;
	}
	return (i);
}
