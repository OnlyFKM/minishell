/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:24:54 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:31:35 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cplst;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		cplst = *lst;
		*lst = cplst->next;
		free(cplst);
	}
	*lst = 0;
}
