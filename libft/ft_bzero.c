/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:37:48 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/06/03 18:11:32 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*be;
	unsigned char	a;
	size_t			i;

	i = 0;
	a = 0;
	be = (unsigned char *)s;
	if (n == 0)
		return ;
	while (i < n)
	{
		be[i] = a;
		i++;
	}
}
