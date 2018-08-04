/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 17:17:08 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/06/02 17:17:11 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *t_lst;
	t_list *t2_lst;
	t_list *new_lst;

	if (!lst || !f)
		return (NULL);
	t_lst = f(ft_lstnew(lst->content, lst->content_size));
	new_lst = ft_lstnew(t_lst->content, t_lst->content_size);
	if (new_lst)
	{
		t2_lst = new_lst;
		while ((lst = lst->next))
		{
			t_lst = f(ft_lstnew(lst->content, lst->content_size));
			t2_lst->next = ft_lstnew(t_lst->content, t_lst->content_size);
			if (!t2_lst->next)
				return (0);
			t2_lst = t2_lst->next;
		}
	}
	return (new_lst);
}
