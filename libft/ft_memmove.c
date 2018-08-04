/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedoryc <ofedoryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 20:07:46 by ofedoryc          #+#    #+#             */
/*   Updated: 2018/05/13 20:07:00 by ofedoryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s_i;
	unsigned char	*d_i;
	size_t			i;

	i = -1;
	s_i = (unsigned char *)src;
	d_i = (unsigned char *)dst;
	if (len == 0)
		return (dst);
	if (src < dst)
	{
		while (len--)
			d_i[len] = s_i[len];
	}
	else if (dst < src)
	{
		while (++i < len)
			d_i[i] = s_i[i];
	}
	return (dst);
}
