/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:24:56 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/12 16:16:28 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*make_map(int size)
{
	int		i;
	int		j;
	t_map	*m;
	char	**p;

	if ((p = (char **)malloc(size * sizeof(char **))) == 0 ||
		(m = (t_map *)malloc(sizeof(t_map))) == 0)
		ft_error();
	i = 0;
	while (i < size)
	{
		p[i] = (char *)malloc(size + 1);
		j = -1;
		while (++j < size)
			p[i][j] = '.';
		p[i][size] = '\0';
		i++;
	}
	m->size = size;
	m->cell = p;
	return (m);
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->cell[i++]);
		ft_putchar('\n');
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		free((void *)(map->cell[i]));
		i++;
	}
	free((void *)(map->cell));
	free((void *)map);
}
