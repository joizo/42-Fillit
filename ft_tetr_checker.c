/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetr_cheker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 03:01:00 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/08/15 21:17:53 by mpetruno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_tetr_elm_check(char *str)
{
	int	i;
	int	elm;

	i = 0;
	if (str[i] != '.' && str[i] != '#')
		return (0);
	elm = 2;
	while (str[++i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if ((str[i] == '\n' && str[i + 1] == '\n') ||
		(str[i] == '\n' && str[i + 1] == '\0'))
		{
			if (elm != 20)
				return (0);
			elm = 0 - (str[i + 1] == '\n');
		}
		elm++;
	}
	return (1);
}

int	ft_resh_check(char *str)
{
	int i;
	int resh;

	i = 0;
	resh = 0;
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') ||
			(str[i] == '\n' && str[i + 1] == '\0'))
		{
			if (resh != 4)
				return (0);
			resh = 0;
		}
		if (str[i] == '#')
			resh++;
		i++;
	}
	return (1);
}

int	ft_comm_tetr(char *str)
{
	int i;
	int comm;
	int	row_3;

	i = -1;
	comm = 0;
	row_3 = 0;
	while (str[++i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') ||
			(str[i] == '\n' && str[i + 1] == '\0'))
		{
			if (comm < 3)
				return (0);
			comm = 0;
			row_3 = -(str[i + 1] == '\n');
			i++;
		}
		comm += (str[i] == '#' && str[i + 1] == '#') +
			(row_3 < 14 && str[i] == '#' && str[i + 5] == '#');
		row_3++;
	}
	return (1);
}

int	ft_tetr_count_check(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i++])
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
			count++;
	return (count);
}

int	ft_sym_row_check(char *str)
{
	int i;
	int sym;
	int row;

	i = -1;
	row = 0;
	while (str[++i])
	{
		sym = 0;
		while (str[i] != '\n' && str[i] != 0)
			sym += (++i) ? 1 : 1;
		if (sym != 4 || str[i] != '\n')
			return (0);
		row++;
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			if (row != 4)
				return (0);
			i = i + (str[i + 1] == '\n');
			row = 0;
		}
	}
	return (1);
}
