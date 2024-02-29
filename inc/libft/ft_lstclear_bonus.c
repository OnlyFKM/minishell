/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:31:37 by frcastil          #+#    #+#             */
/*   Updated: 2023/05/16 13:31:33 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual_l;
	t_list	*next_l;

	if (!lst || !del)
		return ;
	actual_l = *lst;
	while (actual_l)
	{
		next_l = actual_l->next;
		del(actual_l->content);
		free(actual_l);
		actual_l = next_l;
	}
	*lst = 0;
}
