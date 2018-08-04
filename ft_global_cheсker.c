/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global_cheker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 03:01:14 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/07/15 03:01:18 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_tetr_count_check(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i++])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
		count++;
	}
	return (count);
}