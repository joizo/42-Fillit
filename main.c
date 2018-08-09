/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:30:26 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/08/08 17:44:38 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//int	ft_tetr_elm_check(char *s);
void	print_list(t_list *l);
#define BUF_SIZE 545

char	*ft_reader(char *a_v)
{
	int f_open;
	int f_read;
	char *buf;

	if ((f_open = open(a_v, O_RDONLY)) == -1)
		ft_error();
	buf = ft_strnew(BUF_SIZE);
	f_read = read(f_open, buf, BUF_SIZE);
	if (f_read == 0)
		ft_error();
	if (close(f_open) == -1)
		ft_error();
	return (buf);
}

int		main(int a_c, char **a_v)
{
	char	*input_file;
	t_list	*list;
	t_map	*map;

//ft_putstr(a_v[1]);
//ft_putstr(": ");

	if (a_c != 2)
		ft_show_usage();
	input_file = ft_reader(a_v[1]);

	if (ft_checker(input_file) == 0)
		ft_error();
	else
		ft_putchar('\n');
	list = make_list(input_file);
//	print_list(list); // for debug only
	map = make_map(2);
	solve(&map, list);
	print_map(map);
	return (0);
}
