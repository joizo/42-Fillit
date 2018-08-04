/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pov_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 22:38:58 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/06/07 22:39:03 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pov_count(char *s, char n)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!s || !n)
		return (0);
	while (s[i])
	{
		if (s[i] == n)
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}
