/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 20:07:31 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/05/13 20:04:31 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*src_i;
	unsigned char	*dst_i;
	size_t			i;

	i = 0;
	src_i = (unsigned char *)src;
	dst_i = (unsigned char *)dst;
	while (i < n)
	{
		dst_i[i] = src_i[i];
		if (src_i[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
