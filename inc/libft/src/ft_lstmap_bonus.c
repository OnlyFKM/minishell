/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfang <yfang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:56:31 by yfang             #+#    #+#             */
/*   Updated: 2024/02/20 16:31:48 by yfang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*cplst;
	void	*aux;

	if (!lst)
		return (NULL);
	newlst = 0;
	while (lst)
	{
		aux = f(lst->content);
		cplst = ft_lstnew(aux);
		if (cplst)
		{
			ft_lstadd_back(&newlst, cplst);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&newlst, del);
			del(aux);
			return (0);
		}
	}
	return (newlst);
}
