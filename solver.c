/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:48:04 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/12 17:35:59 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set(t_tetr *t, t_map *m, t_point *p, char c)
{
	int	x;
	int	y;
	int i;
	int j;
	int	count;

	i = p->y;
	j = p->x;
	free((void *)p);
	count = 0;
	y = -1;
	while (++y < t->h)
	{
		x = -1;
		while (++x < t->w)
		{
			if (t->cell[y][x] == '#' && m->cell[i + y][j + x] != c)
			{
				m->cell[i + y][j + x] = c;
				count++;
			}
			if (count == 4)
				return ;
		}
	}
}

static int		place(t_tetr *t, t_map *m, int i, int j)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < t->h)
	{
		x = 0;
		while (x < t->w)
		{
			if (t->cell[y][x] == '#' && m->cell[i + y][j + x] == '.')
				count++;
			if (count == 4)
			{
				set(t, m, make_pt(j, i), t->symbol);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int		put(t_list *lst, t_map *m)
{
	int		i;
	int		j;
	t_tetr	*t;

	if (lst == 0)
		return (1);
	i = 0;
	t = (t_tetr *)(lst->content);
	while (i < m->size - t->h + 1)
	{
		j = 0;
		while (j < m->size - t->w + 1)
		{
			if (place(t, m, i, j))
			{
				if (!put(lst->next, m))
					set(t, m, make_pt(j, i), '.');
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

t_map			*solve(t_list *lst)
{
	int		size;
	int		h;
	int		w;
	t_map	*map;

	if (lst == 0)
		ft_error();
	h = ((t_tetr *)(lst->content))->h;
	w = ((t_tetr *)(lst->content))->h;
	size = (h > w) ? h : w;
	map = make_map(size);
	while (!put(lst, map))
	{
		size++;
		free_map(map);
		map = make_map(size);
	}
	return (map);
}
