/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 20:06:44 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/06/03 18:13:06 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}
