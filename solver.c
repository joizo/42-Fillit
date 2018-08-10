/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:48:04 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/10 10:39:59 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		place(t_tetr *t, t_map *m, int i, int j)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < 4 && i + y < m->size)
	{
		x = 0;
		while (x < 4 && j + x < m->size)
		{
			if (t->cell[y][x] == '#' && m->cell[i + y][j + x] == '.')
				count++;
			if (count == 4)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static void		set(t_tetr *t, t_map *m, int i, int j)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < 4 && i + y < m->size)
	{
		x = 0;
		while (x < 4 && j + x < m->size)
		{
			if (t->cell[y][x] == '#' && m->cell[i + y][j + x] == '.')
			{
				m->cell[i + y][j + x] = m->symbol;
				count++;
			}
			if (count == 4)
			{
				m->symbol++;
				return ;
			}
			x++;
		}
		y++;
	}
}

static int		put(t_tetr *t, t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->size)
	{
		j = 0;
		while (j < m->size)
		{
			//if (m->cell[i][j] == '.' && place(t, m, i, j))
			if (place(t, m, i, j))
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


void			solve(t_map **map, t_list *lst)
{
	t_list	*tmp;
	int		size;

	if (map == 0 || lst == 0)
		ft_error();
	tmp = lst;


	while (tmp)
	{
		if (!put((t_tetr *)(tmp->content), *map))
		{
			size = (*map)->size + 1;
			free((void *)(*map));
			*map = make_map(size);
			tmp = lst;
		}
		else
			tmp = tmp->next;
/*
// uncomment this to see solver progress on each step except 1st step when map=2x2

ft_putstr("map size: ");
ft_putnbr((*map)->size);
ft_putchar('\n');
print_map(*map);
ft_putstr("====================\n");
*/
	}
}
