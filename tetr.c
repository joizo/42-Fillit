/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:28:05 by mpetruno          #+#    #+#             */
/*   Updated: 2018/08/12 16:20:05 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	j = 0;
	while (j < 4 && (t->cell[0][j] == '#' || t->cell[1][j] == '#' ||
			t->cell[2][j] == '#' || t->cell[3][j] == '#'))
		j++;
	t->w = j;
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
	i = 0;
	while (i < 4 && (t->cell[i][0] == '#' || t->cell[i][1] == '#' ||
			t->cell[i][2] == '#' || t->cell[i][3] == '#'))
		i++;
	t->h = i;
}

static t_tetr	*make_tetr(char *s, char sym)
{
	t_tetr	*t;
	int		i;
	int		j;

	if ((t = (t_tetr *)malloc(sizeof(t_tetr))) == 0)
		ft_error();
	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			t->cell[i][j] = s[j + i * 5];
		i++;
	}
	t->w = 0;
	t->h = 0;
	t->symbol = sym;
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
	char	symb;

	i = 0;
	list = 0;
	symb = 'A';
	while (inp[i])
	{
		t = make_tetr(inp + i, symb++);
		if ((tmp = ft_lstnew((void *)t, sizeof(t_tetr))) == 0)
			ft_error();
		free((void *)t);
		if (list == 0)
			list = tmp;
		else
			ft_lstadd(&list, tmp);
		i += 20;
		while (inp[i] == '\n')
			i++;
	}
	free((void *)inp);
	return (ft_lstreverse(list));
}

void			free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free((void *)(lst->content));
		free((void *)lst);
		lst = tmp;
	}
}
