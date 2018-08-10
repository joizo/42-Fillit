/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:28:09 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/10 10:31:24 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreverse(t_list *lst)
{
	t_list	*tmp;
	t_list	*prev;

	prev = 0;
	while (lst)
	{
		tmp = lst->next;
		lst->next = prev;
		prev = lst;
		lst = tmp;
	}
	return (prev);
}
