/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:48:04 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/14 15:40:34 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		g_p_x;
static int		g_p_y;

static void		set(t_tetr *t, t_map *m, char c)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = -1;
	while (++y < t->h)
	{
		x = -1;
		while (++x < t->w)
		{
			if (t->cell[y][x] == '#' && m->cell[g_p_y + y][g_p_x + x] != c)
			{
				m->cell[g_p_y + y][g_p_x + x] = c;
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
				g_p_x = j;
				g_p_y = i;
				set(t, m, t->symbol);
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
	t = (t_tetr *)(lst->content);
	i = -1;
	while (++i < m->size - t->h + 1)
	{
		j = -1;
		while (++j < m->size - t->w + 1)
			if (place(t, m, i, j))
			{
				if (!put(lst->next, m))
				{
					g_p_x = j;
					g_p_y = i;
					set(t, m, '.');
				}
				else
					return (1);
			}
	}
	return (0);
}

t_map			*solve(t_list *lst)
{
	int		size;
	int		min_area;
	t_map	*map;

	if (lst == 0)
		ft_error();
	min_area = ft_lstsize(lst) * 4;
	size = 2;
	while (size * size < min_area)
		size++;
	map = make_map(size);
	while (!put(lst, map))
	{
		size++;
		free_map(map);
		map = make_map(size);
	}
	return (map);
}
