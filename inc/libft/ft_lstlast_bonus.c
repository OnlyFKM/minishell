/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:09:01 by frcastil          #+#    #+#             */
/*   Updated: 2023/05/16 15:37:05 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*actual_l;

	if (!lst)
		return (0);
	actual_l = lst;
	while (actual_l->next)
	{
		actual_l = actual_l->next;
	}
	return (actual_l);
}
