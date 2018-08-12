/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 21:30:17 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/08/12 16:39:17 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <fcntl.h>

typedef	struct	s_tetr
{
	char		symbol;
	int			w;
	int			h;
	char		cell[4][4];
}				t_tetr;

typedef	struct	s_map
{
	int			size;
	char		**cell;
}				t_map;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

t_point			*make_pt(int x, int y);
void			ft_error(void);
void			ft_show_usage(void);
char			*ft_reader(char *a_v);
int				ft_checker(char *str);
int				ft_tetr_count_check(char *str);
int				ft_tetr_elm_check(char *str);
int				ft_comm_tetr(char *str);
int				ft_resh_check(char *str);
int				ft_sym_row_check(char *str);
t_list			*make_list(char *inp);
void			free_list(t_list *lst);
t_map			*make_map(int size);
void			print_map(t_map *map);
void			free_map(t_map *map);
t_map			*solve(t_list *lst);

#endif
