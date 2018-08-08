/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:48:04 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/08 18:53:05 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		put(t_term *t, t_map *m)
{

}

void	solve(t_map *map, t_list lst)
{
	t_list	*tmp;
	int		size;

	if (map == 0 || lst == 0)
		ft_error();
	tmp = lst;
	while (tmp)
	{
		if (!put((t_term *)tmp->content, map))
		{
			map = make_map(map->size + 1);
			free((void *)map);
			tmp = lst;
		}
		else
			tmp = tmp->next;
	}
}
