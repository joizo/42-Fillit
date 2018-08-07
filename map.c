/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 17:24:56 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/07 18:03:23 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//fills map with '.'
static t_map	*initiate_map
{

}

t_map			*make_map(int size)
{
	int		i;
	int		j;
	t_map	*m;
	char	**p;
	char	*s;

	if ((p = (char **)malloc(size * sizeof(char **))) == 0 ||
		(m = (t_map*)malloc(t_map)) == 0)
		ft_error();
	if ((m = (t_map*)malloc(t_map)) == 0)

	i = 0;
	while (i < size)
	{
		p[i] = ft_strnew(size);
		s = p[i];
		while (*s)
			*s++ = '.';
	}
	m->size = size;
	m->cell = p;
	return (m);
}

void    print_map(t_map *map)
{

}
