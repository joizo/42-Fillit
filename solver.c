/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:48:04 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/08 20:00:44 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//try to place tetr t on map and return 1 if success, 0 on error.
static int		place(t_tetr *t, t_map *m, int i, int j)
{
	
}

//inserts tetr t into map and iterates letter on map
static void		set(t_tetr *t, t_map *m, int i, int j)
{

}

static int		put(t_term *t, t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->size)
	{
		j = 0;
		while (j < m->size)
		{
			if (m->cell[i][j] == '.' && place(t, m, i, j))
			{
				set(t, m, i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void			solve(t_map *map, t_list lst)
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
			size = map->size + 1;
			free((void *)map);
			map = make_map(size);
			tmp = lst;
		}
		else
			tmp = tmp->next;
	}
}
