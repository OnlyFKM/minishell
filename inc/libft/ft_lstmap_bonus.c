/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:45:21 by frcastil          #+#    #+#             */
/*   Updated: 2023/05/17 13:04:13 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*actual_l;
	void	*aux;

	if (!lst)
		return (0);
	new_l = 0;
	while (lst)
	{
		aux = f(lst->content);
		actual_l = ft_lstnew(aux);
		if (actual_l)
		{
			ft_lstadd_back(&new_l, actual_l);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&new_l, del);
			del(aux);
			return (0);
		}
	}
	return (new_l);
}
