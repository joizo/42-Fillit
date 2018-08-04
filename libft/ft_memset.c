/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 18:32:10 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/06/03 18:09:39 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*be;
	size_t			i;

	i = 0;
	be = (unsigned char *)b;
	while (i < len)
	{
		be[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
