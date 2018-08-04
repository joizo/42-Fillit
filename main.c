/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:30:26 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/07/04 21:30:29 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUF_SIZE 547

char	*ft_reader(char *a_v)
{
	int f_open;
	int f_read;
	char buf[BUF_SIZE + 1];
	char *main_str;

	f_open = open(a_v, O_RDONLY);
	if (f_open == -1)
		ft_error();
	f_read = read(f_open, buf, BUF_SIZE);
	if (buf[0] == 0)
		ft_error();
	buf[f_read] = '\0';
	main_str = ft_strdup(buf);
	close (f_open);
	if (close(f_open == -1))
		ft_error();
	return (main_str);
}

int		main(int a_c, char **a_v)
{
	char *inpt_file;

	if (a_c != 2)
		ft_error();
{
	inpt_file = ft_reader(a_v[1]);
	if (ft_checker(inpt_file) == 0)
	  ft_error();
}
	return (0);
}
