/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:30:17 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/08/08 17:35:04 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h> // for open

typedef	struct	s_tetr
{
	char		cell[4][4];
}				t_tetr;

typedef	struct	s_map
{
	int			size;
	char		**cell;
}				t_map;

//ft_error.c
void	ft_error(void);
void	ft_show_usage(void);

//main.c
char	*ft_reader(char *a_v); // открывает, читает, и закрывает файл

//ft_checker.c
int		ft_checker(char *str);

//ft_global_cheсker.c
int		ft_tetr_count_check(char *str); //количиство tetr 1-26

//ft_tetr_cheсker.c
int		ft_tetr_elm_check(char *str); // к-ство елементов в 1м квадрате, до 21
int		ft_comm_tetr(char *str); // проверка связей между # в квадрате
int		ft_tetr_valid_check(char *str); // проверка квадрата на невалидные символы
int		ft_resh_check(char *str); // проверка на #, должно быть только 4
int		ft_sym_row_check(char *str); // проверка к-ство символов в строке и рядов

//tetr.c
t_list	*make_list(char *inp);

//map.c
t_map	*make_map(int size);
void	print_map(t_map *map);

/*
//solver.c
int		solve(t_map *map);

*/

#endif
