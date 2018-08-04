/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetr_cheker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 03:01:00 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/07/15 03:01:02 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_tetr_elm_check(char *str)
{
	int i;
	int elm;

	i = 0;
	elm = 1;
	while (str[i] != '\0')
	{
		if ((str[i] == '\n' && str[i - 1] == '\n') || 
		(str[i] == '\0' && str[i - 1] == '\n'))
		elm = 0;
		if (elm > 20)
			return (0);
		elm++;
		i++;
	}
	return (1);
}

int	ft_comm_tetr(char *str)
{
	int i;
	int comm;
	int row_3;

	i = -1;
	comm = 0;
	row_3 = 0;
	while (str[++i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') ||
		 (str[i] == '\n' && str[i + 1] == '\0'))
		{
			if (comm != 3 && comm != 4)
				return (0);
		 comm = 0;
		 row_3 = 0;
		}
		if ((str[i] == '#' && str[i + 1] == '#') || 
		(str[i] == '#' && (str[i + 5] == '#' && (row_3 < 14))))
		comm++;
		row_3++;
	}
	return (1);
}

int	ft_tetr_valid_check(char *str)
{
		int i;

		i = 0;
		while (str[i])
		{
			if (str[i] == '#' || str[i] == '.' || str[i] == '\n')
			 i++;
			else
				return (0);
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

int	ft_sym_row_check(char *str)
{
	int i;
	int sym;
	int row;

	i = -1;
	row = 0;
	sym = 0;
	while (str[++i] && str[i + 1])
	{
		if (str[i] == '\n' && str[i - 1] == '\n') 
		{
			if (row != 4)
				return (0);
			i = i + 1;
			row = 0;
		}
		while (str[i] != '\n')
			sym++ && i++;
		if (sym != 4)
			return (0);
		sym = 0;
		row++;
	}
	return (1);
}
