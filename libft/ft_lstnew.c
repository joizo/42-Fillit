/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 17:15:39 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/06/02 19:20:58 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;
	void	*cont1;

	new_node = malloc(sizeof(t_list));
	cont1 = ft_memalloc(content_size);
	if (cont1 == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
		new_node->next = NULL;
		return (new_node);
	}
	cont1 = ft_memcpy(cont1, content, content_size);
	if (new_node)
	{
		new_node->content = cont1;
		new_node->content_size = content_size;
		new_node->next = NULL;
	}
	return (new_node);
}
