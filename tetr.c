/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:28:05 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/08 17:32:19 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//for debug
void		print_tetr(t_tetr *t)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
			ft_putchar(t->cell[i][j]);
		ft_putchar('\n');
	}
	ft_putstr("-------------\n");
}

//for debug
void		print_list(t_list *l)
{
	ft_putstr("Printing list...\n");
	while (l)
	{
		print_tetr((t_tetr *)(l->content));
		l = l->next;
	}
}

static void		offset_h(t_tetr *t)
{
	int	i;
	int	j;

	while (t->cell[0][0] == '.' && t->cell[1][0] == '.' &&
			t->cell[2][0] == '.' && t->cell[3][0] == '.')
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 3)
				t->cell[i][j] = t->cell[i][j + 1];
			t->cell[i][j] = '.';
		}
	}
}

static void		offset_v(t_tetr *t)
{
	int	i;
	int	j;

	while (t->cell[0][0] == '.' && t->cell[0][1] == '.' &&
			t->cell[0][2] == '.' && t->cell[0][3] == '.')
	{
		j = -1;
		while (++j < 4)
		{
			i = -1;
			while (++i < 3)
				t->cell[i][j] = t->cell[i + 1][j];
			t->cell[i][j] = '.';
		}
	}
}

static t_tetr	*make_tetr(char *s)
{
	t_tetr	*t;
	int		i;
	int		j;

	if ((t = (t_tetr *)malloc(sizeof(t_tetr *))) == 0)
		ft_error();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			t->cell[i][j] = s[j + i * 5];
			j++;
		}
		i++;
	}
	offset_h(t);
	offset_v(t);
	return (t);
}

t_list			*make_list(char *inp)
{
	int		i;
	t_tetr	*t;
	t_list	*list;
	t_list	*tmp;

	i = 0;
	list = 0;
	while (inp[i])
	{
		t = make_tetr(inp + i);
		if ((tmp = ft_lstnew((void *)t, sizeof(t_tetr))) == 0)
			ft_error();
		if (list == 0)
			list = tmp;
		else
			ft_lstadd(&list, tmp);
		i += 20;
		while (inp[i] == '\n')
			i++;
	}
	free((void *)inp);
	return (list);
}
