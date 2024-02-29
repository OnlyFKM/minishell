/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:58:56 by frcastil          #+#    #+#             */
/*   Updated: 2023/05/16 13:31:10 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	int		i;
	t_list	*actual_l;

	if (!lst)
		return (0);
	i = 1;
	actual_l = lst;
	while (actual_l->next)
	{
		i++;
		actual_l = actual_l->next;
	}
	return (i);
}
